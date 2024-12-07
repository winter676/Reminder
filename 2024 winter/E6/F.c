#include<stdio.h>
#include<math.h>
int main()
{
    int frontx[20000],xbehind[20000],num = 0,num2 = 0;
    char temp,front = '=',rubbish;
    scanf("f(x)",&rubbish);
    while (scanf("%c",&temp) != EOF)
    {
        if (temp == 'x' && (front == '=' || front == '+'))
        {
            frontx[num] = 1;
            num ++;
        }
        if (temp == 'x' && (front != '=' && front != '+'))
        {
            frontx[num] = front - '0';
            num ++;
        }
        if (front == '^')
        {
            xbehind[num2] = temp - '0';
            num2++;
        }
        if (front == 'x' && temp != '^')
        {
            xbehind[num2] = 1;
            num2++;
        }
        front = temp;
    }

        printf("f'(x)=");
        for (int i = 0; i < num2; i++ )
        {
            if (frontx[i] != 1)
            {
                printf("%d",frontx[i]*xbehind[i]);
            }
            if (xbehind[i] != 1)
            {
                printf("x");
                if (xbehind[i] != 2)
                {
                    printf("^");
                    printf("%d",xbehind[i]-1);
                }
                printf("+");
            }
            if (xbehind[i] == 1)
            {
                break;
            }
        }
    return 0;
}
