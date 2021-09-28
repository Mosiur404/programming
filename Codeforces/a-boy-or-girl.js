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
    const username = readLine().trim();
    let temp = {}, total = 0;
    for (let i = 0; i < username.length; i++) {
        if (!temp[username[i]]) {
            temp[username[i]] = 1;
            total++;
        }
    }
    let result = (total % 2 === 0) ? 'CHAT WITH HER!' : 'IGNORE HIM!';
    console.log(result);
}
