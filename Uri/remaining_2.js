
var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let A = parseInt(lines.shift());

for (let i = 0; i <= 10000; i++) {
    if (i % A == 2) console.log(i);
}
