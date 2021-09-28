var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let M = parseInt(lines.shift());

let months = [
    'January',
    'February',
    'March',
    'April',
    'May',
    'June',
    'July',
    'August',
    'September',
    'October',
    'November',
    'December'
];
console.log(months[M - 1]);