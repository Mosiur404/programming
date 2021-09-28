var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var N = parseInt(lines.shift());
let i;
for (i = 1; i <= N && N <= 1000; i++) {
    if (i % 2 !== 0) console.log(i);
}