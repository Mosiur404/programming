var readline = require("readline");

var input = [];

var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.prompt();

rl.on("line", function (cmd) {
  input.push(cmd);
});

rl.on("close", function (cmd) {
  console.log(input.join("\n"));
  process.exit(0);
});
