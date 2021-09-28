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
  const cases = 3; // number of links/weights
  const startNode = [];
  const endNode = [];
  const weights = [];
  // 1 2 5
  // 2 3 7
  // 3 1 9
  // 4 1 0
  //input
  for (let n = 0; n < cases; n++) {
    const temp = readLine()
      .split(" ")
      .map((e) => parseInt(e));

    startNode.push(temp[0]);
    endNode.push(temp[1]);
    weights.push(temp[2]);
  }

  //output
  for (let i = 0; i < cases; i++) {
    if (weights[i] === 0) continue;
    console.log(`node ${startNode[i]} - ${endNode[i]} weight = ${weights[i]}`);
    console.log(`node ${endNode[i]} - ${startNode[i]} weight = ${weights[i]}`);
  }
}
