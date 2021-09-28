let i = 1; j = 7;
while (i <= 9) {
    console.log(`I=${i} J=${j}`);
    j--;
    if (j == 4) {
        i++;
        i++;
        j = 7;
    }
}