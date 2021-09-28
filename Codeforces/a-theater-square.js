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
    let [n, m, a] = readLine().split(' ').map(Number);
    let x = 0, y = 0;
    if (n % a == 0) x = n / a;
    else x = Math.floor(n / a) + 1
    if (m % a == 0) y = m / a;
    else y = Math.floor(m / a) + 1
    console.log(x * y);
}