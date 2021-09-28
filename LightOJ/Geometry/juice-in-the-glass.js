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
        const [r1, r2, h, p] = readLine().split(' ').map(Number);

        const constant = (r1 - r2) / h
        const increase = constant * p;
        const radius = r2 + increase;
        const waterVolume = volume(r2, radius, p);
        console.log(`Case ${i}: ${waterVolume.toFixed(10)}`);
    }
}

function volume(r1, r2, h) {
    //  1/3 * pi * (r1S + r1* r2 + r2S)h
    return (Math.PI / 3) * h * (Math.pow(r1, 2) + (r1 * r2) + Math.pow(r2, 2));
}