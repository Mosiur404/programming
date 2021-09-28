var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var [X, Y] = lines.shift().split(' ').map(e => { return parseFloat(e); });

if (X === 0 && Y === 0) return console.log('Origem');
else if (X === 0) return console.log('Eixo Y');
else if (Y === 0) return console.log('Eixo X');

//x=2 y=3 

let D = ((Math.atan2(Y, X) * (180 / Math.PI)) + 360) % 360;

if (D > 0 && D < 90) console.log('Q1');
else if (D > 90 && D < 180) console.log('Q2');
else if (D > 180 && D < 270) console.log('Q3');
else if (D > 270 && D < 360) console.log('Q4');

