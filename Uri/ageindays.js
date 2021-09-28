var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var age = parseInt(lines.shift()); //days

var year = parseInt(age / 365);
age = age % 365;

var month = parseInt(age / 30);

var days = age % 30;

console.log(`${year} ano(s)\n${month} mes(es)\n${days} dia(s)`);