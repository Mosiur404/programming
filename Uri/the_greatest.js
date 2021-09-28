var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var s = (lines.shift().split(' '));
var A = parseInt(s[0]);
var B = parseInt(s[1]);
var C = parseInt(s[2]);

var AB = ((A + B) + Math.abs(A - B)) / 2;
var geatest = ((AB + C) + Math.abs(AB - C)) / 2;

console.log(`${geatest} eh o maior`);