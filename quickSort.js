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
  const arrayLength = parseInt(readLine());
  const arr = readLine()
    .split(" ")
    .map((e) => parseInt(e));
  arr.push(Number.MAX_SAFE_INTEGER);
  quickSort(arr, 0, arrayLength);
  arr.pop();
  console.log(arr);
}

function quickSort(arr, low, high) {
  if (low < high) {
    const j = partition(arr, low, high);
    quickSort(arr, low, j);
    quickSort(arr, j + 1, high);
  }
}
function partition(arr, low, high) {
  const pivot = arr[low];
  let i = low;
  let j = high;
  while (i < j) {
    do {
      i++;
    } while (arr[i] <= pivot);

    do {
      j--;
    } while (arr[j] > pivot);

    if (i < j) {
      //do swap
      [arr[i], arr[j]] = [arr[j], arr[i]];
    }
  }
  [arr[low], arr[j]] = [arr[j], arr[low]];
  return j;
}
