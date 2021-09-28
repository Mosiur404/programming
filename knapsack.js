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
  // 60, 120, 100
  // 10, 30, 20
  // 50
  const profits = readLine()
    .split(" ")
    .map((e) => parseInt(e));
  const weights = readLine()
    .split(" ")
    .map((e) => parseInt(e));
  let knapsack_capacity = parseInt(readLine());

  //profits / weights
  const ratio = profits.map((profit, index) => {
    if (profit === 0 || weights[index] === 0) return 0;
    return profit / weights[index];
  });

  sortAll(profits, weights, ratio);

  const output = fillKnapsack(profits, weights, knapsack_capacity);
  console.log(output);
}

function sortAll(profits, weights, ratio) {
  for (let i = 0; i < profits.length - 1; i++) {
    for (let j = 0; j < profits.length - i - 1; j++) {
      if (ratio[j] < ratio[j + 1]) {
        // swap
        [ratio[j], ratio[j + 1]] = [ratio[j + 1], ratio[j]];
        [profits[j], profits[j + 1]] = [profits[j + 1], profits[j]];
        [weights[j], weights[j + 1]] = [weights[j + 1], weights[j]];
      }
    }
  }
}

function fillKnapsack(profits, weights, knapsack_capacity) {
  let totalProfit = (i = 0);
  const arraySize = profits.length || 0;

  for (i = 0; i < arraySize; i++) {
    if (weights[i] > knapsack_capacity) break;
    totalProfit += profits[i];
    knapsack_capacity -= weights[i];
  }

  // fill the remains with fraction
  if (i < arraySize && knapsack_capacity > 0) {
    const ratio = profits[i] / weights[i];
    totalProfit += ratio * knapsack_capacity;
  }
  return totalProfit;
}
