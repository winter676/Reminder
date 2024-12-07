#include <stdio.h>

void permute(int *arr, int l, int r);
void swap(int *a, int *b);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    permute(arr, 0, n - 1);
    return 0;
}

void permute(int *arr, int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i <= r; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(&arr[l], &arr[i]);
            permute(arr, l + 1, r);
            swap(&arr[l], &arr[i]); // 回溯
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}