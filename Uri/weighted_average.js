var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let N = parseInt(lines.shift());
let temp, t;

let weight = [2, 3, 5];

let sum = 2 + 3 + 5;

for (let i = 0; i < N; i++) {
    temp = []; t = 0;
    temp = lines.shift().split(' ').map((e) => { return parseFloat(e) });
    for (let j = 0; j < temp.length; j++) {
        t = t + (temp[j] * weight[j]);
    }
    console.log((t / sum).toFixed(1));
}