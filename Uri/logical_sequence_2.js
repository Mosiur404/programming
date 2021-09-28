var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let A = lines.shift().split(' ').map(e => { return parseInt(e); });

let i, j, temp = 1;

for (i = 1; i <= A[1]; i++) {
    for (j = 1; j <= A[0]; j++) {
        if (temp > A[1])
            break;
        if (j == 1) {
            process.stdout.write(`${temp++}`);
        }
        else process.stdout.write(` ${temp++}`);

    }
    process.stdout.write('\n');
    if (temp > A[1]) break;
}
