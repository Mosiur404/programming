var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let A = lines.filter(e => { return (e !== ''); }).map(e => { return parseInt(e); });
//cleaned
let fuel = {
    'key': ['Alcool', 'Gasolina', 'Diesel'],
    'value': [0, 0, 0]
};
for (let i = 0; i < A.length; i++) {
    if (!(A[i] >= 0 && A[i] <= 4)) continue;
    else if (A[i] == 4) break;
    fuel.value[A[i] - 1]++;
}

console.log('MUITO OBRIGADO');
(fuel.key).forEach((element, i) => {
    console.log(`${element}: ${fuel.value[i]}`);
});

