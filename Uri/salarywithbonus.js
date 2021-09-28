var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var NAME = lines.shift();
var SALARY = parseInt(lines.shift());
var SOLD = parseFloat(lines.shift());

var TOTAL = (SALARY + (SOLD * 15 / 100)).toFixed(2);

console.log(`TOTAL = R$ ${TOTAL}`);