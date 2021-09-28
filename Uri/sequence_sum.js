var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let S = lines.map(k => { return k.split(' ').map(j => { return parseInt(j); }); });//cleaned

S = S.map(e => {
    return (e[0] > e[1]) ? [e[1], e[0]] : e;
}
); //sorted

let i, str, t;
S.forEach((e, index) => {
    str = ''; t = 0;
    if (e[0] > 0 && e[1] > 0) {
        for (i = e[0]; i <= e[1]; i++) {
            str += i + ' ';
            t += i;
        }
        console.log(str + 'Sum=' + t);
    }
});