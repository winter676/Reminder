#include<stdio.h>
char key[1000],a[1000],t[1000];
int main()
{
    int n;
    scanf("%d\n",&n);
    for (int i = 0; i < n; i++ )
    {
        scanf("%c",&key[i]);
    }
    scanf("\n");
    for (int i = 0; i < n; i++ )
    {
        scanf("%c",&a[i]);
    }
    for (int i = 0; i < n; i++ )
    {
        t[i] = a[i] - (key[i] % 26);
        if (a[i] >= 'a' && t[i] < 'a')
        {
            t[i] += 26;
        }
        if (a[i] >= 'A' && t[i] < 'A')
        {
            t[i] += 26;
        }
    }
    for (int i = 0; i < n; i++ )
    {
        printf("%c",t[i]);
    }
}