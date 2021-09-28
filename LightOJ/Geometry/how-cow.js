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
        const [x1, y1, x2, y2] = readLine().split(' ').map(Number);
        const M = parseInt(readLine());
        console.log(`Case ${i}:`);
        for (let j = 0; j < M; j++) {
            const [x, y] = readLine().split(' ').map(Number);
            if (x > x1 && x < x2 && y > y1 && y < y2) console.log('Yes');
            else console.log('No');
        }
    }
}
