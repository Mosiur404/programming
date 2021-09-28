var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let N = parseInt(lines.shift());

let f1 = 0, f2 = 1, i = 2, temp = 0;
let str = '0';
while (i <= N) {
    temp = f1 + f2;
    f1 = f2;
    f2 = temp;
    str += ` ${f1}`;
    i++;
}

console.log(str);