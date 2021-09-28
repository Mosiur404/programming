var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

const [A, B, C] = (lines.shift().split(' ').map(function (c) { return parseFloat(c); }));

if (A <= 0 || (B * B - 4 * A * C) < 0) {
    console.log('Impossivel calcular');
    return;
}
let D = Math.sqrt(B * B - 4 * A * C);
let R1 = ((-B + D) / (2 * A)).toFixed(5);
let R2 = ((-B - D) / (2 * A)).toFixed(5);

console.log(`R1 = ${R1}`);
console.log(`R2 = ${R2}`);