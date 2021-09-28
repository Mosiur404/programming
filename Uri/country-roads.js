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

    let m = [], n = [], A = {}, t = [];
    for(let i = 0;i<cases;i++){
        A[i] = [];
    [m[i], n[i]] = readLine().split(' ').map(Number)
    for (let j = 0; j < n[i]; j++) {
        let [u, v, w] = readLine().split(' ').map(Number);
        A[i][j] = { u, v, w };
    }
    t[i] = parseInt(readLine());
}
    console.log(m, n, '\n', A, t);
}