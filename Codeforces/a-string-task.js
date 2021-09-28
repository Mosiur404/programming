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
    const str = readLine().toLowerCase();
    let result = '';
    let vowelSet = { a: true, o: true, y: true, e: true, u: true, i: true }
    for (let i = 0; i < str.length; i++) {
        if (vowelSet[str[i]]) continue;
        else result += '.' + str[i];
    }
    console.log(result);
}