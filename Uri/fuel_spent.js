var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var perlitter = 12; //km/L

var spent_time = parseInt(lines.shift()); //hour
var avg_speed = parseInt(lines.shift()); //km/h

var total_distance = spent_time * avg_speed; //km

var need_fuel = (total_distance / perlitter).toFixed(3);
console.log(need_fuel);
