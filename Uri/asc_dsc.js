var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let S = lines.map(k => { return k.split(' ').map(j => { return parseInt(j); }); });//cleaned

for (let i = 0; i < S.length; i++) {
    if (S[i][0] == S[i][1]) break;
    else if (S[i][0] > S[i][1]) console.log('Decrescente');
    else console.log('Crescente');
}

for (let t = 0; t < array.length; t++) {
    const element = array[t];

}