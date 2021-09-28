var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var NUMBER = (parseInt(lines.shift()));
var hours = (parseInt(lines.shift()));
var rate = (parseFloat(lines.shift()));

var SALARY = (hours * rate).toFixed(2);
console.log(`NUMBER = ${NUMBER}`);
console.log(`SALARY = U$ ${SALARY}`);