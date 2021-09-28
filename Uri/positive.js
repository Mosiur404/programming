var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let numbers = lines.map(e => { return parseFloat(e) });
let j = 0;
numbers.forEach((elem, i) => {
    if (elem >= 0) j++;
});
console.log(`${j} valores positivos`);