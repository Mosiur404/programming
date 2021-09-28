var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let S = lines.map(j => { return parseInt(j); });//cleaned
let pass = '2002';
for (let i = 0; i < S.length; i++) {
    if (S[i] == pass) { console.log('Acesso Permitido'); break; }
    else console.log('Senha Invalida');
}