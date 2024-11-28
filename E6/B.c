#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char study[1200];
    int sum = 0,max = 0;
    gets(study);
    for (int i = 0 ; i < strlen(study); i++ )
    {
        if(study[i] == 'S')
        {
            max ++;
            sum += max;
        }
        else
        {
            max = 0;
        }
    }
    printf("%d\n",sum);
    return 0;
}