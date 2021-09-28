const { SSL_OP_SSLEAY_080_CLIENT_DH_BUG } = require('constants');

var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let numbers = lines.map(e => { return parseFloat(e); });

let total = numberofitem = 0;
numbers.forEach((e, i) => {
    if (e > 0) {
        total += e;
        numberofitem++;
    }
});
numberofitem = (numberofitem) ? numberofitem : 1;
console.log(`${numberofitem} valores positivos`);
console.log((total / numberofitem).toFixed(1));
