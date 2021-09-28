
var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let A = parseInt(lines.shift());
let B = parseInt(lines.shift());

if (A > B) [A, B] = [B, A];
let odd = 0;
for (++A; A < B; A++) {
    if (A % 2 !== 0) {
        odd += A;
    }
}

console.log(odd);