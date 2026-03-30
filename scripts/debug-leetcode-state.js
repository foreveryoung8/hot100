const { execFileSync } = require("child_process");

const bin = process.argv[2];
for (const mode of ["default", "-T"]) {
  const args = [bin, "list"];
  if (mode === "-T") args.push("-T");
  const out = execFileSync("node", args, { encoding: "utf8" });
  const lines = out.split(/\r?\n/);
  for (const id of ["35", "118"]) {
    const line = lines.find((l) => new RegExp(`\\[\\s*${id}\\s*\\]`).test(l));
    if (!line) {
      console.log(mode, id, "line-not-found");
      continue;
    }
    const m = line.match(/^(.)\s(.{1,2})\s(.)\s\[\s*(\d*)\s*\]/);
    if (!m) {
      console.log(mode, id, "prefix-no-match", JSON.stringify(line.slice(0, 24)));
      continue;
    }
    const state = m[3];
    console.log(mode, id, `stateCp=U+${state.codePointAt(0).toString(16).toUpperCase()}`, `state=${JSON.stringify(state)}`);
  }
}
