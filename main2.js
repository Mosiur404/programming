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
        const length = parseInt(readLine());
        const arr = readLine().split(' ').map(Number);
        let localMax = 0;
        let globalMax = 10e6;
        for (let j = 0; j < length; j++) {
            localMax = Math.max(arr[j], arr[j] + localMax);
            if (localMax > globalMax) {
                globalMax = localMax;
            }
        }
        console.log(globalMax);
    }
    // console.log(`Case ${i}: ${str}`);
}

