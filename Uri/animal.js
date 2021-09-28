var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let animal = lines.map(e => { return e.replace('\r', ''); });

let animals = {
    'vertebrado': {
        'ave': { 'carnivoro': 'aguia', 'onivoro': 'pomba' },
        'mamifero': { 'onivoro': 'homem', 'herbivoro': 'vaca' }
    },
    'invertebrado': {
        'inseto': { 'hematofago': 'pulga', 'herbivoro': 'lagarta' },
        'anelideo': { 'hematofago': 'sanguessuga', 'onivoro': 'minhoca' }
    },
};

console.log(animals[animal[0]][animal[1]][animal[2]]);
