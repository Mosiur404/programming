var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var [A, B, C, D] = lines.shift().split(' ').map((item) => { return parseFloat(item) });

let AVG = ((A * 2) + (B * 3) + (C * 4) + D) / (2 + 3 + 4 + 1);

console.log(`Media: ${AVG.toFixed(1)}`);
if (AVG >= 7.0) console.log('Aluno aprovado.');
else if (AVG < 5.0) console.log('Aluno reprovado.');
else if (AVG >= 5 && AVG <= 6.9) {

    var X = parseFloat(lines.shift());

    console.log('Aluno em exame.');
    console.log(`Nota do exame: ${X.toFixed(1)}`);

    AVG = (AVG + X) / 2;

    if (AVG >= 5.0) console.log(`Aluno aprovado.`);
    else if (AVG <= 4.9) console.log(`Aluno reprovado.`)
    console.log(`Media final: ${AVG.toFixed(1)}`);
}




