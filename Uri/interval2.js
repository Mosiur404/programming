var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let Out = 0, In = 0, i;
let N = lines.shift();
for (i = 0; i < N; i++) {
    lines[i] = parseInt(lines[i]);

    if (lines[i] >= 10 && lines[i] <= 20) In++;
    else Out++;
}
console.log(`${In} in`);
console.log(`${Out} out`);