var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let i;
let N = lines.shift();
for (i = 0; i < N; i++) {
    lines[i] = parseInt(lines[i]);
    if (lines[i] === 0) {
        console.log('NULL');
        continue;
    }
    if (lines[i] % 2 == 0) {
        if (lines[i] < 0) console.log('EVEN NEGATIVE');
        else console.log('EVEN POSITIVE');
    }
    else {
        if (lines[i] < 0) console.log('ODD NEGATIVE');
        else console.log('ODD POSITIVE');
    }
}