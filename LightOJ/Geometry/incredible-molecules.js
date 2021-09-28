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
        const [x1, y1, r1, x2, y2, r2] = readLine().split(' ').map(Number);
        let segment;
        const [r1Square, r2Square] = [r1 * r1, r2 * r2];
        // Case 1: 78.5398163397
        const AB = Math.sqrt(
            Math.pow((x2 - x1), 2) + Math.pow((y2 - y1), 2)
            , 2);

        if ((r1 + r2) <= AB) segment = 0;
        else if ((r1 + r2) >= AB && (Math.abs(r1 - r2)) < AB) {
            let theta1 = 2 * theta(r1, AB, r2);
            let theta2 = 2 * theta(r2, AB, r1);
            const triangle1 = iseclesArea(theta1, r1);
            const triangle2 = iseclesArea(theta2, r2);
            const sector1 = 0.5 * r1Square * theta1;
            const sector2 = 0.5 * r2Square * theta2;

            segment = sector1 - triangle1 + sector2 - triangle2;
        }
        else {
            let r;
            if (r1 > r2) r = r2;
            else r = r1;
            segment = Math.PI * Math.pow(r, 2);
        }
        console.log(`Case ${i}: ${segment}`);
    }
}

function iseclesArea(theta, sameSide) {
    return 0.5 * Math.pow(sameSide, 2) * Math.sin(theta);
}
function theta(x, y, z) {
    return Math.acos(
        (Math.pow(x, 2) + Math.pow(y, 2) - Math.pow(z, 2))
        /
        (2.00 * x * y)
    );
}