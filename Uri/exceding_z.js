var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

lines = lines.map(e => { return parseInt(e) });
let A = lines.shift();
let X;
for (let i = 0; i < lines.length; i++) {
    if (lines[i] > A) {
        X = lines[i];
        break;
    }
}
let i = 0, temp = 0;
while (true) {
    temp += A + i;
    if (temp > X) {
        break;
    }
    i++;
}
console.log(i + 1);
// 3 4 5 6