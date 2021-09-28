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
        const n = parseInt(readLine());
        const cord = [];
        for (let j = 0; j < n; j++) {
            const [x, y] = readLine().split(' ').map(Number);
            cord.push([x, y]); // cord = coordinates
        }
        let temp = {}, total = 0;
        for (let k = 0; k < n - 1; k++) {
            for (let l = k + 1; l < n; l++) {
                const [x1, y1, x2, y2] = [cord[k][0], cord[k][1], cord[l][0], cord[l][1]];
                let mid = midpoint(x1, y1, x2, y2).join(', ');
                console.log(mid);
                if (temp[mid]) {
                    total++;
                    // console.log(mid);
                }
                else {
                    temp[mid] = true;
                }
            }
        }
        console.log(total);
        break
        // console.log(`Case ${i}: `);
    }
}

const midpoint = (x1, y1, x2, y2) => {
    return [((x2 + x1) / 2), ((y2 + y1) / 2)];
}
