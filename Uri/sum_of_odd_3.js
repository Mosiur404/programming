
var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let l = parseInt(lines.shift());
let i = 0, j = 0, total = 0;

A = lines.map(e => { return e.split(' ').map(j => { return parseInt(j); }) });

for (i = 0; i < l; i++) {
    while (j < A[i][1]) {
        if (A[i][0] % 2 !== 0) {
            j++;
            total += A[i][0];
        }
        A[i][0]++;
    }
    console.log(total);
    j = 0;
    total = 0;
}


// console.log(l, A);
