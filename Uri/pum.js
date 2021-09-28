var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let A = lines.filter(e => { return (e !== ''); }).map(e => { return parseInt(e); });
let temp = 1;
for (let i = 1; i <= A; i++) {
    console.log(`${temp++} ${temp++} ${temp++} PUM`);
    temp++;
}