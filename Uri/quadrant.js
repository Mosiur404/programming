var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

//string  = '2 3'
// string = ['2','3']
let S = lines.map(e => { return e.split(' ').map(j => { return parseInt(j); }); }); //cleaned

let degree;
for (let i = 0; i < S.length; i++) {
    if (S[i][0] === 0 || S[i][1] === 0 || S[i][0] == 'undefined' || S[i][1] == 'undefined') break;

    degree = (Math.atan2(S[i][1], S[i][0]) * (180 / Math.PI) + 360) % 360;

    if (degree > 0 && degree < 90) console.log('primeiro');
    else if (degree > 90 && degree < 180) console.log('segundo');
    else if (degree > 180 && degree < 270) console.log('terceiro');
    else if (degree > 270 && degree < 360) console.log('quarto');
}
