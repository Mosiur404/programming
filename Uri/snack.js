var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

const [X, Y] = lines.shift().split(' ').map((c) => { return parseInt(c); })

const price = [4.00, 4.50, 5.00, 2.00, 1.50];

console.log(`Total: R$ ${(price[X - 1] * Y).toFixed(2)}`);