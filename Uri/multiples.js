var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let [A, B] = lines.shift().split(' ').map(e => { return parseInt(e) });
if (B > A) {
    if (B % A === 0) console.log('Sao Multiplos');
    else console.log('Nao sao Multiplos');
}
else {
    if (A % B === 0) console.log('Sao Multiplos');
    else console.log('Nao sao Multiplos');
}