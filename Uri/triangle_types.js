var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');


let ARR = lines.shift().split(' ').map(e => { return parseFloat(e); });

let i = j = 0;
for (i = 0; i < ARR.length - 1; i++) {
    for (j = 0; j < ARR.length - i - 1; j++) {
        if (ARR[j] < ARR[j + 1]) {
            [ARR[j], ARR[j + 1]] = [ARR[j + 1], ARR[j]];
        }
    }
}
let [A, B, C] = ARR;
let A2 = Math.pow(A, 2);
let B2 = Math.pow(B, 2);
let C2 = Math.pow(C, 2);
if (A >= (B + C)) console.log('NAO FORMA TRIANGULO');
else {
    if (A2 == (B2 + C2)) console.log('TRIANGULO RETANGULO');
    if (A2 > (B2 + C2)) console.log('TRIANGULO OBTUSANGULO');
    if (A2 < (B2 + C2)) console.log('TRIANGULO ACUTANGULO');
    if (A == B && B == C) console.log('TRIANGULO EQUILATERO');
    if ((A == B && A != C) || (C == A && C != B) || (B == C && B != A)) console.log('TRIANGULO ISOSCELES');
}
console.log(C);
// if A ≥ B + C, write the message: NAO FORMA TRIANGULO
// if A2 = B2 + C2, write the message: TRIANGULO RETANGULO
// if A2 > B2 + C2, write the message: TRIANGULO OBTUSANGULO
// if A2 < B2 + C2, write the message: TRIANGULO ACUTANGULO
// if the three sides are the same size, write the message: TRIANGULO EQUILATERO
// if only two sides are the same and the third one is different, write the message: TRIANGULO ISOSCELES