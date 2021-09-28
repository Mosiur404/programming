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
        const [Ax, Ay, Bx, By, Cx, Cy] = readLine().split(' ').map(Number);
        // console.log(Ax, Ay, Bx, By, Cx, Cy);
        const ab = Math.sqrt(
            Math.pow(Bx - Ax, 2) + Math.pow(By - Ay, 2)
            , 2);
        const bc = Math.sqrt(
            Math.pow(Cx - Bx, 2) + Math.pow(Cy - By, 2)
            , 2);
        const ca = Math.sqrt(
            Math.pow(Ax - Cx, 2) + Math.pow(Ay - Cy, 2)
            , 2);
        const theta = Math.acos(
            (Math.pow(ab, 2) + Math.pow(bc, 2) - Math.pow(ca, 2))
            /
            (2.00 * ab * bc)
        );
        let [Dx, Dy] = [Ax + Cx - Bx, Ay + Cy - By];
        // console.log(Dx, Dy);
        console.log(`Case ${i + 1}: ${Dx} ${Dy} ${(ab * bc * Math.sin(theta)).toFixed(0)}`);
    }
    //another way is finding midpoint
}