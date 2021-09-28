var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

var s = (lines.shift().split(' '));
var A = parseFloat(s[0]);
var B = parseFloat(s[1]);
var C = parseFloat(s[2]);

var TRIANGULO = (1 / 2 * A * C).toFixed(3);
var CIRCULO = (3.14159 * C * C).toFixed(3);
var TRAPEZIO = (C / 2 * (A + B)).toFixed(3);
var QUADRADO = (B * B).toFixed(3);
var RETANGULO = (A * B).toFixed(3);

console.log(`TRIANGULO: ${TRIANGULO}`);
console.log(`CIRCULO: ${CIRCULO}`);
console.log(`TRAPEZIO: ${TRAPEZIO}`);
console.log(`QUADRADO: ${QUADRADO}`);
console.log(`RETANGULO: ${RETANGULO}`);