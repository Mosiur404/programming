
var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let l = parseInt(lines.shift());
let i, total;

lines = lines.filter(e => { return !(e == '\r' || e == ''); });
lines.forEach(e => {
    total = 0;
    e = (e.split(' ').map(e => { return parseInt(e); }));
    if (e[0] > e[1]) [e[0], e[1]] = [e[1], e[0]];
    if (e[0] !== e[1]) {
        for (i = e[0] + 1; i < e[1]; i++) {
            if (i % 2 !== 0) total += i;
        }
    }
    console.log(total);
});
