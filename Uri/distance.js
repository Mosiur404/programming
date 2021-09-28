var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var car1 = 60; //km/hour
var car2 = 90; //km/hour

var difference = 60 / (car2 - car1); //per minute

var distance = lines.shift(); //scan input

console.log(distance * difference + ' minutos');