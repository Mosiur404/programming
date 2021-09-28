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
        const [AB, AC, BC, ratio] = readLine().split(' ').map(Number);
        // Given AB,BC,AC, ADE/BDEC
        // AD/AB = AE/EC = DE/BC
        // △ADE/△ABC= (AD/AB)^2 = (AE/AC)^2 = (DE/BC)^2
        // AD = Sqrt(ADE/ABC) * AB
        // ratio = ADE / BDEC , BDEC = 1, ADE = ratio, ABC = ratio + 1
        // AD = Sqrt(r/ABC) * AB
        const ABC = ratio + 1;
        const AD = Math.sqrt(ratio / ABC) * AB;
        console.log(`Case ${i}: ${AD.toFixed(10)}`);
    }
}
