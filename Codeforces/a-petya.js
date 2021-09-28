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
  const str1 = readLine().toLowerCase();
  const str2 = readLine().toLowerCase();
  let counter = 0;
  for (let i = 0; i < str1.length; i++) {
    if (str1[i] == str2[i]) continue;

    if (str1[i].charCodeAt(0) > str2[i].charCodeAt(0)) counter++;
    else counter--;
    break;
  }
  console.log(counter);
}
