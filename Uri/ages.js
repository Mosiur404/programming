var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let Ages = lines.filter(e => { return (e !== '' && e >= 0); }).map(e => { return parseInt(e); });

let avg = Ages.reduce((a, c) => { return a + c; }) / Ages.length;

console.log(avg.toFixed(2));