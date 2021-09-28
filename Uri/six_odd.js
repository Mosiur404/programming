var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let N = parseInt(lines.shift());
let i = 0;
while (i < 6) {
    if (N % 2 !== 0) {
        console.log(N);
        i++;
    }
    N++;
}