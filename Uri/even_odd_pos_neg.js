const { captureRejectionSymbol } = require('events');

var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let i = 0, even = 0, odd = 0, pos = 0, neg = 0;

for (i = 0; i < 5; i++) {
    lines[i] = parseInt(lines[i]);
    if (lines[i] === 0) { even++; continue; }

    if ((lines[i] % 2) === 0) even++;
    else odd++;

    if (lines[i] < 0) neg++;
    else if (lines[i] > 0) pos++;
}

console.log(`${even} valor(es) par(es)`);
console.log(`${odd} valor(es) impar(es)`);
console.log(`${pos} valor(es) positivo(s)`);
console.log(`${neg} valor(es) negativo(s)`);
