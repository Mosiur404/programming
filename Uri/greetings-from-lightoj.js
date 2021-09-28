process.stdin.resume()
process.stdin.setEncoding('utf-8')

let currentLine = 0
let inputString = ''

process.stdin.on('data', raw_data => {
    inputString += raw_data
})

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(line => {
        return line.trim();
    })
    main();
})

function readLine() {
    return inputString[currentLine++]
}

function main() {
    const N = parseInt(readLine());
    for (let i = 0; i < N; i++) {
        let [A, B] = readLine().split(' ').map(Number);
        console.log(`Case ${i + 1}: ${A + B}`);
    }
}