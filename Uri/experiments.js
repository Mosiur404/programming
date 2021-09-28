var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

l = parseInt(lines.shift());

let [i, total, coelhos, ratos, sapos] = [0, 0, 0, 0, 0];

for (i; i < l; i++) {
    lines[i] = lines[i].split(' ');
    lines[i][0] = parseInt(lines[i][0]); //convert into int
    lines[i][1] = lines[i][1].replace('\r', ''); //convert into string

    if (lines[i][1] === 'C') {
        coelhos += lines[i][0];
    }
    else if (lines[i][1] === 'R') {
        ratos += lines[i][0];
    }
    else {
        sapos += lines[i][0];
    }
    total += lines[i][0];
}

console.log(`Total: ${total} cobaias`);
console.log(`Total de coelhos: ${coelhos}`);
console.log(`Total de ratos: ${ratos}`);
console.log(`Total de sapos: ${sapos}`);

console.log(`Percentual de coelhos: ${(coelhos * (100 / total)).toFixed(2)} %`);
console.log(`Percentual de ratos: ${(ratos * (100 / total)).toFixed(2)} %`);
console.log(`Percentual de sapos: ${(sapos * (100 / total)).toFixed(2)} %`);
