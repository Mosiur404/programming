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
        const cubes = parseInt(readLine());
        let [xh, yh, zh, xl, yl, zl] = [1000, 1000, 1000, 0, 0, 0];
        for (let j = 0; j < cubes; j++) {
            const [x1, y1, z1, x2, y2, z2] = readLine().split(' ').map(Number);
            xl = Math.max(xl, x1);
            xh = Math.min(xh, x2);

            yl = Math.max(yl, y1);
            yh = Math.min(yh, y2);

            zl = Math.max(zl, z1);
            zh = Math.min(zh, z2);
        }

        const intersection = (xh - xl) * (yh - yl) * (zh - zl);
        console.log(`Case ${i}: ${intersection > 0 ? intersection : 0}`);
    }
}
