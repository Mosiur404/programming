var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


var X = lines.shift().split(' ');
var Y = lines.shift().split(' ');

var x1 = parseFloat(X[0]);
var y1 = parseFloat(X[1]);
var x2 = parseFloat(Y[0]);
var y2 = parseFloat(Y[1]);

var distance = Math.sqrt(Math.pow((x2 - x1), 2) + Math.pow((y2 - y1), 2), 2).toFixed(4);

console.log(distance);