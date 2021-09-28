var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var total = parseInt(lines.shift()); //usd

console.log(total);

// 544

var notes = [100, 50, 20, 10, 5, 2, 1];

notes.forEach(function (item) {
    if (total >= item) {
        console.log(`${parseInt(total / item)} nota(s) de R$ ${item},00`);
        total = total % item;
    }
    else console.log(`0 nota(s) de R$ ${item},00`);
});



//use this 

// for (let i = 0; i < notes.length; i++) {
//     if (total >= notes[i]) {
//         console.log(`${parseInt(total / notes[i])} nota(s) de R$ ${notes[i]},00`);
//         total = total % notes[i];
//     }
//     else console.log(`0 nota(s) de R$ ${notes[i]},00`);
// }

//or this
