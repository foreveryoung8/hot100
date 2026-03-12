const fs = require("fs");
const path = require("path");
const { chromium } = require("playwright");

const STUDYPLAN_URL = "https://leetcode.cn/studyplan/top-100-liked/";
const LOGIN_URL = "https://leetcode.cn/accounts/login/";
const USER_DATA_DIR = path.join(__dirname, "..", ".leetcode-profile");
const LOGIN_TIMEOUT_MS = 30 * 60 * 1000;
const MUTATION = `mutation addQuestionToDefaultFavoriteV2($questionSlug: String!) {
  addQuestionToDefaultFavoriteV2(questionSlug: $questionSlug) {
    ok
    error
  }
}`;

function ensureDir(dir) {
  if (!fs.existsSync(dir)) {
    fs.mkdirSync(dir, { recursive: true });
  }
}

async function hasLogin(context) {
  const cookies = await context.cookies("https://leetcode.cn");
  return cookies.some((cookie) => cookie.name === "LEETCODE_SESSION" && cookie.value);
}

async function waitForLogin(page, context) {
  if (await hasLogin(context)) {
    console.log("检测到已登录，继续执行。");
    return;
  }

  console.log("已打开登录页，请在浏览器中完成 LeetCode CN 登录。");
  console.log("登录成功后脚本会自动继续。");
  await page.goto(LOGIN_URL, { waitUntil: "domcontentloaded", timeout: 60000 });

  const deadline = Date.now() + LOGIN_TIMEOUT_MS;
  while (Date.now() < deadline) {
    if (await hasLogin(context)) {
      console.log("已检测到登录状态。");
      await page.waitForTimeout(2000);
      return;
    }
    await page.waitForTimeout(2000);
  }

  throw new Error("等待登录超时，请重新运行脚本。");
}

async function fetchHot100Slugs(page) {
  await page.goto(STUDYPLAN_URL, { waitUntil: "domcontentloaded", timeout: 60000 });
  const nextDataText = await page.locator("script#__NEXT_DATA__").textContent({ timeout: 30000 });
  if (!nextDataText) {
    throw new Error("未找到学习计划页面数据。");
  }

  const nextData = JSON.parse(nextDataText);
  const queries = nextData?.props?.pageProps?.dehydratedState?.queries ?? [];
  const detail = queries
    .map((item) => item?.state?.data?.studyPlanV2Detail)
    .find(Boolean);

  if (!detail?.planSubGroups?.length) {
    throw new Error("未能从学习计划页面提取题目列表。");
  }

  const slugs = detail.planSubGroups
    .flatMap((group) => group.questions ?? [])
    .map((question) => question.titleSlug)
    .filter(Boolean);

  return [...new Set(slugs)];
}

async function getCsrfToken(context) {
  const cookies = await context.cookies("https://leetcode.cn");
  return cookies.find((cookie) => cookie.name === "csrftoken")?.value ?? "";
}

async function addQuestionToDefaultFavorite(context, questionSlug) {
  const csrfToken = await getCsrfToken(context);
  const response = await context.request.post("https://leetcode.cn/graphql/", {
    headers: {
      "content-type": "application/json",
      "x-csrftoken": csrfToken,
      referer: STUDYPLAN_URL,
    },
    data: {
      query: MUTATION,
      variables: { questionSlug },
    },
  });

  return {
    status: response.status(),
    payload: await response.json(),
  };
}

function normalizeResult(result) {
  const payload = result?.payload ?? {};
  const gqlError = payload?.errors?.[0]?.message;
  const mutationData = payload?.data?.addQuestionToDefaultFavoriteV2;
  const error = mutationData?.error ?? gqlError ?? "";

  if (mutationData?.ok) {
    return { ok: true, message: "" };
  }

  return { ok: false, message: String(error || "未知错误") };
}

async function main() {
  ensureDir(USER_DATA_DIR);

  const context = await chromium.launchPersistentContext(USER_DATA_DIR, {
    headless: false,
    viewport: { width: 1440, height: 900 },
  });

  const page = context.pages()[0] ?? (await context.newPage());

  try {
    await waitForLogin(page, context);

    const slugs = await fetchHot100Slugs(page);
    if (!slugs.length) {
      throw new Error("Hot 100 题目列表为空。");
    }

    console.log(`已提取 ${slugs.length} 道题，开始加入默认收藏夹。`);

    let successCount = 0;
    const failures = [];

    for (let index = 0; index < slugs.length; index += 1) {
      const slug = slugs[index];
      let result;
      let attempts = 0;

      while (true) {
        attempts += 1;
        result = normalizeResult(await addQuestionToDefaultFavorite(context, slug));
        if (!result.message.includes("用户未登录") || attempts >= 15) {
          break;
        }
        console.log(`[${index + 1}/${slugs.length}] 登录态未就绪，等待后重试: ${slug}`);
        await page.waitForTimeout(2000);
      }

      if (result.ok) {
        successCount += 1;
        console.log(`[${index + 1}/${slugs.length}] 已加入: ${slug}`);
      } else {
        failures.push({ slug, message: result.message });
        console.log(`[${index + 1}/${slugs.length}] 失败: ${slug} -> ${result.message}`);
      }

      await page.waitForTimeout(150);
    }

    console.log("");
    console.log(`完成。成功 ${successCount} / ${slugs.length}。`);
    if (failures.length) {
      console.log("失败列表:");
      for (const failure of failures) {
        console.log(`- ${failure.slug}: ${failure.message}`);
      }
    }
  } finally {
    await context.close();
  }
}

main().catch((error) => {
  console.error(error);
  process.exitCode = 1;
});
