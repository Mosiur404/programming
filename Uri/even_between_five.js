var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let numbers = lines.map(e => { return parseInt(e); });

let numberofitem = 0;
numbers.forEach((e, i) => {
    if ((e % 2) === 0) {
        numberofitem++;
    }
});
console.log(`${numberofitem} valores pares`);
