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
    for (let i = 0; i < cases; i++) {
        const [oX, oY, aX, aY, bX, bY] = readLine().split(' ').map(Number);
        const a = Math.sqrt(
            Math.pow((aX - oX), 2) + Math.pow((aY - oY), 2)
            , 2);
        const b = Math.sqrt(
            Math.pow((bX - oX), 2) + Math.pow((bY - oY), 2)
            , 2);
        const c = Math.sqrt(
            Math.pow((bX - aX), 2) + Math.pow((bY - aY), 2)
            , 2);

        const theta = Math.acos(
            (Math.pow(a, 2) + Math.pow(b, 2) - Math.pow(c, 2))
            /
            (2.00 * a * b)
        );
        console.log(`Case ${i + 1}: ${(theta * a).toFixed(8)}`);
    }

}