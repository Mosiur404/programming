var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var A = (parseFloat(lines.shift()));
var B = (parseFloat(lines.shift()));

var MEDIA = ((A * 3.5 + B * 7.5) / (3.5 + 7.5)).toFixed(5);
console.log(`MEDIA = ${MEDIA}`);
