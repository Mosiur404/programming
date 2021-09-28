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
    const stones = readLine().trim();
    let total = 0;
    for (let i = 0; i < cases - 1; i++) {
        if (stones[i] == stones[i + 1]) total++;
    }
    console.log(total);
}
