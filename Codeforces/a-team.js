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
    const cases = parseInt(readLine());
    let total = 0;
    let temp = '';
    for (let i = 0; i < cases; i++) {
        temp = readLine().split(' ').join('');
        if (temp.indexOf('11') != -1 || temp.indexOf('101') != -1) total++;
    }
    console.log(total);
}