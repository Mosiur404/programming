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
  const cases = 5; //number of nodes

  let input = [];

  for (let n = 0; n < cases; n++) {
    const temp = readLine()
      .split(" ")
      .map((e) => parseInt(e));
    input.push(temp);
  }

  for (let i = 0; i < input.length; i++) {
    for (let j = 0; j < input[i].length; j++) {
      if (input[i][j] === 0) continue;
      console.log(`node ${i + 1} - ${j + 1} weight = ${input[i][j]}`);
    }
  }
}
