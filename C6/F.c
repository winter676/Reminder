#include<stdio.h>
#include<string.h>
int main()
{
    int k,a,b,x,y,bor[20][20],len;
    char s[1000];
    for (int i = 0; i < 5; i++ )
    {
        scanf("%d%d%d",&k,&a,&b);
        gets(s);
        len = strlen(s);
        for (int j = 0; j < k ; j++ )
        {
            printf("%d%d",&x,&y);
            bor[x][y] = 1;
        }
        x = 0;
        y = 0;
        for (int j = 0; j < len; j++ )
        {
            if (s[j] == 'N')
            {
                if (y <= -1 || bor[x][y+1])
                {
                    continue;
                }
                else
                {
                    y++;
                }
            }
            else if (s[j] == 'E')
            {
                if (x <= -1 || bor[x+1][y])
                {
                    continue;
                }
                else
                {
                    x++;
                }
            }
            else if (s[j] == 'S')
            {
                if (y <= 1 || bor[x][y-1])
                {
                    continue;
                }
                else
                {
                    y--;
                }
            }
            else if (s[j] == 'W')
            {
                if (x <= 1 || bor[x-1][y])
                {
                    continue;
                }
                else
                {
                    x--;
                }
            }
        }
    }
    return 0;
}
