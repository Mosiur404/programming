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
//code starts from here
function main() {
  const numberOfItems = parseInt(readLine());
  const inputArray = readLine()
    .split(" ")
    .map((e) => parseInt(e));
  // input is done
  mergeSort(0, numberOfItems - 1, inputArray);
  console.log(inputArray);
}

function mergeSort(low, high, arr) {
  if (low < high) {
    const mid = Math.floor((low + high) / 2);
    // do left half
    mergeSort(low, mid, arr);
    //do right half
    mergeSort(mid + 1, high, arr);

    merge(low, mid, high, arr);
  }
}

function merge(low, mid, high, arr) {
  // create new temp arrays
  const n1 = mid - low + 1;
  const n2 = high - mid;
  const leftArray = new Array(n1);
  const rightArray = new Array(n2);

  for (let i = 0; i < n1; i++) {
    leftArray[i] = arr[low + i];
  }
  for (let j = 0; j < n2; j++) {
    rightArray[j] = arr[mid + 1 + j];
  }
  let i = 0;
  let j = 0;
  let k = low;
  while (i < n1 && j < n2) {
    if (leftArray[i] <= rightArray[j]) {
      arr[k] = leftArray[i];
      i++;
    } else {
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = rightArray[j];
    j++;
    k++;
  }
}
