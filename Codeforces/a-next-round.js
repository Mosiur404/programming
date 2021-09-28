process.stdin.resume();
process.stdin.setEncoding("utf-8");

let currentLine = 0;
let inputString = "";

process.stdin.on("data", (raw_data) => {
  inputString += raw_data;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((line) => {
      return line.trim();
    });
  main();
});

function readLine() {
  return inputString[currentLine++];
}

function main() {
  const [cases, position] = readLine().split(" ").map(Number);
  const scores = readLine().split(" ").map(Number);
  const minimum = scores[position - 1];
  let total = 0;
  for (let i = cases - 1; i >= 0; i--) {
    if (scores[i] && scores[i] >= minimum) {
      total++;
    }
  }
  console.log(total);
}
