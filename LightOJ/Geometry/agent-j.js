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
        const [r1, r2, r3] = readLine().split(' ').map(Number);
        const a = r1 + r2;
        const b = r2 + r3;
        const c = r3 + r1;
        const s = (a + b + c) / 2;
        const areaTriangle = Math.sqrt(
            (s * (s - a) * (s - b) * (s - c))
        );
        const cR1a = theta(a, c, b);
        const cR2a = theta(a, b, c);
        const cR3a = theta(b, c, a);

        const segment1 = .5 * Math.pow(r1, 2) * cR1a;
        const segment2 = .5 * Math.pow(r2, 2) * cR2a;
        const segment3 = .5 * Math.pow(r3, 2) * cR3a;

        console.log(`Case ${i}: ${(areaTriangle - (segment1 + segment2 + segment3)).toFixed(10)}`);
    }
}

function theta(x, y, z) {
    return Math.acos(
        (Math.pow(x, 2) + Math.pow(y, 2) - Math.pow(z, 2))
        /
        (2.00 * x * y)
    );
}