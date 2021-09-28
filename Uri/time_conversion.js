var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var time = parseInt(lines.shift()); //second

var hour = parseInt(time / 3600);
time = time % 3600;
var minute = parseInt(time / 60);
var second = time % 60;

console.log(`${hour}:${minute}:${second}`);