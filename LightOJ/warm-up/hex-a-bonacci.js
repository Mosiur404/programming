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
        const [a, b, c, d, e, f, n] = readLine().split(' ').map(Number);
        // printf("Case %d: %d\n", caseno, fn(n) % 10000007);
        console.log(`Case ${i}: ${fn(a, b, c, d, e, f, n) % 10000007}`);
    }
}

function fn(a, b, c, d, e, f, n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    return fn(n - 1) + fn(n - 2) + fn(n - 3) + fn(n - 4) + fn(n - 5) + fn(n - 6);
}
