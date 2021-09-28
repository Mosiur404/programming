var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var total = parseFloat(lines.shift()); //usd

var notes = [100, 50, 20, 10, 5, 2];
var coins = [1, 0.50, 0.25, 0.10, 0.05, 0.01];
console.log('NOTAS:');
for (i = 0; i < notes.length; i++) {
    console.log(`${parseInt(total / notes[i])} nota(s) de R$ ${notes[i].toFixed(2)}`);
    total = (total % notes[i]).toFixed(2);
}
console.log('MOEDAS:');
for (i = 0; i < coins.length; i++) {
    console.log(`${parseInt(total / coins[i])} moeda(s) de R$ ${coins[i].toFixed(2)}`);
    total = (total % coins[i]).toFixed(2);
}