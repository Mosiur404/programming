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
        const [a, b, c, d] = readLine().split(' ').map(Number);
        const h = height(a - c, b, d);
        const area = (h / 2 * (a + c));
        console.log(`Case ${i}: ${area.toFixed(10)}`);
    }
}

function height(x, y, z) {
    const s = (x + y + z) / 2;
    const triangleArea = Math.sqrt(
        s * (s - x) * (s - y) * (s - z)
    );
    return Math.abs((triangleArea * 2) / x);

}