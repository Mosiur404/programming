var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let d = lines.shift();

let list = {
    '61': 'Brasilia',
    '71': 'Salvador',
    '11': 'Sao Paulo',
    '21': 'Rio de Janeiro',
    '32': 'Juiz de Fora',
    '19': 'Campinas',
    '27': 'Vitoria',
    '31': 'Belo Horizonte'
};
if (list[d] != null) console.log(list[d]);
else console.log('DDD nao cadastrado');