var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let temp = '';
for (let j = 0; j < lines.length; j++) {
    lines[j] = parseInt(lines[j]);
    if (lines[j] === 0) break;
    for (let i = 1; i <= lines[j]; i++) {
        if (i == 1) temp += (`${i}`)
        else temp += (` ${i}`)
    }
    temp += ('\n');
}
process.stdout.write(temp);
