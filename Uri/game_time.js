var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let [S, E] = lines.shift().split(' ').map(e => { return parseInt(e); });

if (S < E) {
    console.log(`O JOGO DUROU ${E - S} HORA(S)`);
}
else {
    console.log(`O JOGO DUROU ${(E + 24) - S} HORA(S)`)
}

