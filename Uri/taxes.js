var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let A = parseFloat(lines.shift());

let R = t = 0;
let tax = () => {
    if (A <= 2000) return;
    if (A > 4500) {
        R = A - 4500;
        t += R * 28 / 100;
        A = 4500;
    }
    else if (A > 3000) {
        R = A - 3000;
        t += R * 18 / 100;
        A = 3000;
    }
    else if (A > 2000) {
        R = A - 2000;
        t += R * 8 / 100;
        A = 2000;
    }
    tax();
}
if (A <= 2000) console.log('Isento')
else { tax(); console.log(`R$ ${t.toFixed(2)}`); }

// let arr = [
//     [2000.01, 3000.00, 8],
//     [3000.01, 4500.00, 18],
//     [4500.01, Number.POSITIVE_INFINITY, 28],
// ];