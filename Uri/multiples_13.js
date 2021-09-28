var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let [A, B] = lines.filter(e => { return (e !== ''); }).map(e => { return parseInt(e); });
//cleaned
let total = 0;
[A, B] = (A < B) ? [A, B] : [B, A];
// sort
for (let i = A; i <= B; i++) {
    if (i % 13 !== 0) total += i;
}
console.log(total);