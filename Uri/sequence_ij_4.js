let i = 0; j = 0, k = 0;
while (i <= 2) {
    while (k <= 2) {
        j = k + i + 1;
        console.log(`I=${i} J=${j}`);
        k++;
    }
    i = Math.round((i + 0.2) * 1e12) / 1e12;
    k = 0;
}

