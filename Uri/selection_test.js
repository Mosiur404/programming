var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

const [A, B, C, D] = (lines.shift().split(' ').map(function (c) { return parseInt(c); }));

let text = (B > C && D > A && (C + D) > (A + B) && C >= 0 && D >= 0 && (A % 2 === 0)) ? 'Valores aceitos' : 'Valores nao aceitos';
console.log(text);