var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var X = parseFloat(lines.shift());
var Y = parseFloat(lines.shift());

var G = (X / Y).toFixed(3);

console.log(`${G} km/l`);