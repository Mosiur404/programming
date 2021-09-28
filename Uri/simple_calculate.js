var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var PROD1 = lines.shift().split(' ');
var PROD2 = lines.shift().split(' ');

var TOTAL = (PROD1[1] * PROD1[2] + PROD2[1] * PROD2[2]).toFixed(2);

console.log(`VALOR A PAGAR: R$ ${TOTAL}`);