var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let d = parseInt(lines.shift());

let temp = '';

for (let i = 1; i <= d / 2; i++) {
    if (d % i === 0) temp += `${i}\n`;
}
console.log(temp + d);