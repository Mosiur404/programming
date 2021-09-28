
var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


lines = lines.map(e => { return parseInt(e); });
let N = lines.shift();

let nChoose2 = e => {
    return (e * (e - 1)) / 2;
};
let nChoose4 = e => {
    return (e * (e - 1) * (e - 2) * (e - 3)) / (2 * 3 * 4);
};

console.log(1 + nChoose2(N) + nChoose4(N));