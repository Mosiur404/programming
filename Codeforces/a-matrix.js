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
  let arr = [];
  let row = 0,
    column = 0;
  for (let i = 0; i < 5; i++) {
    arr.push(readLine().split(" ").map(Number));
    if (arr[i].indexOf(1) != -1) {
      [row, column] = [i + 1, arr[i].indexOf(1) + 1];
    }
  }
  row = row < 3 ? 3 - row : row - 3;
  column = column < 3 ? 3 - column : column - 3;
  console.log(row + column);
}
