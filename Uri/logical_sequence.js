var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let A = lines.filter(e => { return (e !== ''); }).map(e => { return parseInt(e); });

for (let i = 1; i <= A; i++) {
    process.stdout.write(`${Math.pow(i, 1)} ${Math.pow(i, 2)} ${Math.pow(i, 3)}`);
    process.stdout.write('\n');
    process.stdout.write(`${Math.pow(i, 1)} ${Math.pow(i, 2) + 1} ${Math.pow(i, 3) + 1}`);
    process.stdout.write('\n');
}