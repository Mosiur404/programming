var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let [A, B, C] = lines.shift().split(' ').map(e => { return parseFloat(e) });

if ((A + B) > C && (A + C) > B && (B + C) > A) {
    console.log(`Perimetro = ${(A + B + C).toFixed(1)}`);
} else console.log(`Area = ${((C / 2) * (A + B)).toFixed(1)}`);