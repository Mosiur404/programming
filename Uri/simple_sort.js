var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let i = j = 0;
let A = lines.shift().split(' ').map(e => { return parseFloat(e) });
const B = A.join('\n');
for (i = 0; i < A.length - 1; i++) {
    for (j = 0; j < A.length - i - 1; j++) {
        if (A[j] > A[j + 1]) {
            [A[j], A[j + 1]] = [A[j + 1], A[j]];
        }
    }
}

console.log(A.join('\n'));
console.log('');
console.log(B);