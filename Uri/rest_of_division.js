var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let [A, B] = lines.filter(e => { return (e !== ''); }).map(e => { return parseInt(e); });
//cleaned
let temp = 0;
[A, B] = (A < B) ? [A, B] : [B, A];
// sort
for (let i = A + 1; i < B; i++) {
    temp = i % 5;
    if (temp == 2 || temp == 3) console.log(i);

}