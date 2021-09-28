var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let l = parseInt(lines.shift());

let S = lines.map(e => { return e.split(' ').map(j => { return parseInt(j); }); }); //cleaned

for (let i = 0; i < l; i++) {
    if (S[i][1] === 0) {
        console.log('divisao impossivel');
        continue;
    }
    else console.log((S[i][0] / S[i][1]).toFixed(1));
}