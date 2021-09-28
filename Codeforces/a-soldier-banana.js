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
    let [k, n, w] = readLine().split(' ').map(Number);
    for (let i = 1; i <= w; i++) {
        n = n - (k * i);
    }
    n = (n < 0) ? n * -1 : 0;
    console.log(n);
}