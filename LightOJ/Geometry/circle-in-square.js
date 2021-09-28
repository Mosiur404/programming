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
        const r = readLine().split(' ').map(Number);
        const areaOfSquare = Math.pow(r * 2, 2);
        const areaOfCircle = Math.PI * Math.pow(r, 2);
        const remainingSPaces = areaOfSquare - areaOfCircle;
        console.log(`Case ${i}: ${remainingSPaces.toFixed(2)}`);
    }
}
