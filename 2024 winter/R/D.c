#include <stdio.h>
#include <string.h>

char num1[15000],num2[15000];
int result[15000];

int isOverflow(char num1[], char num2[], int n);

int main()
{
    int t, n;
    scanf("%d%d", &t, &n);
    getchar();

    while (t--) {
        gets(num1);
        gets(num2);


        if (isOverflow(num1, num2, n)) {
            printf("0verFLOW!\n");
        } else {
            printf("Not 0verFLOW\n");
        }
    }

    return 0;
}

int isOverflow(char num1[], char num2[], int n)
{
    int carry = 0;

    for (int i = n - 1; i >= 0; i--) {
        int bit1 = num1[i] - '0';
        int bit2 = num2[i] - '0';
        result[i + 1] = bit1 + bit2 + carry;
        carry = result[i + 1] / 2;
        result[i + 1] %= 2;
    }
    result[0] = carry;

    int sign1 = num1[0] - '0';
    int sign2 = num2[0] - '0';
    int signResult = result[1];

    if (sign1 == 0 && sign2 == 0 && signResult == 1) {
        return 1;
    }

    if (sign1 == 1 && sign2 == 1 && signResult == 0) {
        return 1;
    }

    return 0;
}