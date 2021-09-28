let i = 1; j = 7, k = 0;
while (i <= 9) {
    k++;
    console.log(`I=${i} J=${j}`);
    j--;
    if (k % 3 == 0) {
        i++;
        i++;
        j += 5;
    }
}