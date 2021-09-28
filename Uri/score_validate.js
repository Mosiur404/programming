var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let A = lines.filter(e => { return (e !== ''); });
//cleaned
let total = 0, n = 0;
for (let i = 0; i < A.length; i++) {
    A[i] = parseFloat(A[i]);
    if (n == 2) {
        console.log(`media = ${(total / 2).toFixed(2)}`);
        n = 0;
    }
    if (A[i] < 0 || A[i] > 10) {
        console.log('nota invalida');
        continue;
    }
    else total += A[i];
    n++;
}