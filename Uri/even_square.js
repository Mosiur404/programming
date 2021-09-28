var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let N = lines.shift();
let i;

for (i = 2; i <= N; i++) {
    if (i % 2 === 0) {
        console.log(`${i}^2 = ${(i * i)}`);
    }
}

console.log(N);

