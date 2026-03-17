# Hot100

用于整理 LeetCode Hot 100 题解的轻量仓库。

## 目录结构

- `solutions/cpp/`: C++ 题解文件
- `scripts/`: 辅助脚本
- `.vscode/`: 本地调试和编辑器配置

## 使用说明

日常刷题直接把题解放进 `solutions/cpp/`。

如果还需要把 LeetCode 热题 100 批量加入默认收藏夹：

```bash
npm install
npm run favorite:hot100
```

脚本会打开浏览器，登录 `leetcode.cn` 后自动继续执行。

## Local Customizations

- Favorites list in the VS Code LeetCode panel shows `tag1` first and full `tags` at the end, and is sorted by `tag1` (primary) then `difficulty` (secondary). This is implemented by patching the extension files under `%USERPROFILE%\.vscode\extensions\leetcode.vscode-leetcode-0.18.4\out\src\explorer\` and will be overwritten by extension updates.
- Generated solution file names are customized via workspace setting in `.vscode/settings.json` using `leetcode.filePath.cpp.filename` (current format: `${id}.${difficulty}.${name}.${tag}.${ext}`).
