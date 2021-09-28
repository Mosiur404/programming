var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let salary = parseFloat(lines.shift());

let P = [
    [0, 400.00, 15],
    [400.01, 800.00, 12],
    [800.01, 1200.00, 10],
    [1200.01, 2000.00, 7],
    [2000.00, false, 4]
];

P.forEach((item) => {
    let raise;
    if (salary > item[0] && item[1] == false) {
        raise = salary * (item[2] / 100);
        console.log(`Novo salario: ${(salary + raise).toFixed(2)}`);
        console.log(`Reajuste ganho: ${(raise).toFixed(2)}`);
        console.log(`Em percentual: ${item[2]} %`);
        return;
    }
    else if (salary >= item[0] && salary <= item[1]) {
        raise = salary * (item[2] / 100);
        console.log(`Novo salario: ${(salary + raise).toFixed(2)}`);
        console.log(`Reajuste ganho: ${(raise).toFixed(2)}`);
        console.log(`Em percentual: ${item[2]} %`);
    }
});