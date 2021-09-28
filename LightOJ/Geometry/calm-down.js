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
    const cases = parseInt(readLine());
    for (let i = 1; i <= cases; i++) {
        const [R, n] = readLine().split(' ').map(Number);

        const theta = 360 / n;
        const piByn = Math.PI / n;
        const r = (R * Math.sin(piByn)) / (1 + Math.sin(piByn));
        console.log(`Case ${i}: ${r.toFixed(10)}`);
    }
}
