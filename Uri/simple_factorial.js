var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let N = parseInt(lines.shift());

let fib = (e) => {
    if (e <= 1) return 1;
    return e * fib(e - 1);
}
console.log(fib(N));