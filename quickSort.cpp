#include <stdio.h>
void quicksort(int a[], int first, int last)
{
    int pivot, i, j, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;

            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, 0, j - i);
        quicksort(a, j + 1, last);
    }
}

int main()
{
    int a[50], n, i;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    printf("Enter the array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", a[i]);
        quicksort(a, 0, n - 1);
    }
    printf("Sorted elements are:\n");

    for (i = 0; i < n; i++)
        printf("%d", a[i]);

    return 0;
}