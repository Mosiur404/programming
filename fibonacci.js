// function fib(n) {
//     let result = 1;
//     for (let i = 1; i <= n; i++) {
//         result *= i
//     }
//     console.log(result);
// }
// function fib1(n) {
//     if (n <= 1) return 1;
//     return n * fib(n - 1);
// }

function fib(n) {
    // console.log(n);
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (fib(n - 1) + fib(n - 2));
}

let t = fib(0);
console.log(t);

