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
        readLine();//clear empty input
        const houses = parseInt(readLine());
        let colors = [];
        for (let j = 0; j < houses; j++) {
            const [R, G, B] = readLine().split(' ').map(Number);
            colors.push([R, G, B]);
        }

        // let [top, bottom] = [Math.min(...colors[0]), Math.min(...colors[houses - 1])];
        // console.log(top, bottom);
        // if (top < bottom) {
        let min = Math.min(...colors[0]);
        let tracker = colors[0].indexOf(min);
        // console.log(tracker);
        let temp = 0;
        for (let m = 1; m < houses; m++) {
            colors[m][tracker] = 1001;
            temp = Math.min(...colors[m]);
            console.log(temp);
            tracker = colors[m].indexOf(temp);
            min += temp;
        }
        // console.log(min);
        // }
        // else console.log(bottom);
        console.log(`Case ${i}: ${min}`);
    }
}
