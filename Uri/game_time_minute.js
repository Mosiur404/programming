var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let [S, SM, E, EM] = lines.shift().split(' ').map(e => { return parseInt(e); });
let M = H = 0;

S = (S * 60) + SM;//minute
E = (E * 60) + EM;//minute

if (S == E) {
    H = 24;
}
else if (S < E) {
    H = parseInt((E - S) / 60);
    M = (E - S) % 60;
}
else {
    H = parseInt((E + (60 * 24) - S) / 60);
    M = (E + (60 * 24) - S) % 60;
}
console.log(`O JOGO DUROU ${H} HORA(S) E ${M} MINUTO(S)`);
