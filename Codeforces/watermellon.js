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
    const W = parseInt(readLine());
    if (W % 2 === 0) {
        if (W <= 2) console.log('NO');
        else console.log('YES');
    }
    else console.log('NO');
}