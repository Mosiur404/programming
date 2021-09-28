
var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let arr = lines.map((e) => { return parseInt(e); });

let max = 0; pos = 0;
arr.forEach((e, i) => {
    if (max < e) {
        max = e;
        pos = i + 1;
    }
});
console.log(max);
console.log(pos);