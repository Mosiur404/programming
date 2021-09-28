var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var A = (parseInt(lines.shift()));
var B = (parseInt(lines.shift()));
var C = (parseInt(lines.shift()));
var D = (parseInt(lines.shift()));

var DIFERENCA = (A * B) - (C * D);
console.log(`DIFERENCA = ${DIFERENCA}`);