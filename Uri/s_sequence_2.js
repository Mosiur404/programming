let i, S = 1; j = 1;
for (i = 2; i <= 39; i++) {
    if (i % 2 == 0) continue;
    S += i / (j *= 2);
}
console.log(S.toFixed(2));