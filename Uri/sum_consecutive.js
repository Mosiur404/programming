var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let [A, N] = lines.shift().split(' ').map(e => { return parseInt(e); }).filter(e => { return (e > 0); });
let temp = A;
for (let i = 1; i < N; i++) {
    A++;
    temp += A;
}

console.log(temp);