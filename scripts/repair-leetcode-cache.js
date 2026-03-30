const fs = require("fs");
const os = require("os");
const path = require("path");

const HOME = os.homedir();
const LC_ROOT = path.join(HOME, ".lc");
const TARGETS = [
  path.join(LC_ROOT, "leetcode", "cache"),
  path.join(LC_ROOT, "leetcode.cn", "cache"),
];

function resetDir(dir) {
  if (!fs.existsSync(dir)) {
    return { changed: false, reason: "not-found" };
  }

  fs.rmSync(dir, { recursive: true, force: true });
  fs.mkdirSync(dir, { recursive: true });
  return { changed: true };
}

function main() {
  console.log("LeetCode cache repair started.");
  console.log(`Target root: ${LC_ROOT}`);

  const results = [];
  for (const target of TARGETS) {
    try {
      const result = resetDir(target);
      results.push({ target, ...result });
    } catch (error) {
      results.push({ target, changed: false, reason: String(error.message || error) });
    }
  }

  console.log("");
  console.log("Repair summary:");
  for (const item of results) {
    if (item.changed) {
      console.log(`- reset: ${item.target}`);
    } else {
      console.log(`- skip:  ${item.target} (${item.reason})`);
    }
  }

  console.log("");
  console.log("Next steps in VS Code:");
  console.log("1) Run: LeetCode: Sign Out (optional but recommended)");
  console.log("2) Run: LeetCode: Sign In");
  console.log("3) Run: LeetCode: Refresh");
  console.log("4) Run: Developer: Reload Window");
}

main();