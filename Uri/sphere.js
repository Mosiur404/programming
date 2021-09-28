var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var r = parseFloat(lines.shift());

var volume = (4.00 / 3 * 3.14159 * r * r * r).toFixed(3);

console.log(`VOLUME = ${volume}`);