var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

let R, H, M, S;
let SD = parseInt(lines.shift().replace('Dia ', ''));
let ST = lines.shift().split(' : ').map(e => { return parseInt(e); });
let ED = parseInt(lines.shift().replace('Dia ', ''));
let ET = lines.shift().split(' : ').map(e => { return parseInt(e); });

ST_in_second = (ST[0] * 60 * 60) + (ST[1] * 60) + ST[2];
ET_in_second = (ET[0] * 60 * 60) + (ET[1] * 60) + ET[2];

if (ET_in_second < ST_in_second) {
    ET_in_second += (24 * 60 * 60);
    ED -= 1;
}

R = ET_in_second - ST_in_second;
H = parseInt(R / (60 * 60));
R = R % (60 * 60);
M = parseInt(R / 60);
S = R % 60;


console.log(`${ED - SD} dia(s)`);
console.log(`${H} hora(s)`);
console.log(`${M} minuto(s)`);
console.log(`${S} segundo(s)`);

