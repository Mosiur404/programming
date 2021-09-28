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
    let [Limak, Bob] = readLine().split(' ').map(Number);
    let i = 1;
    while (true) {
        Limak *= 3;
        Bob *= 2;
        if (Limak > Bob) break;
        i++;
    }
    console.log(i);
}