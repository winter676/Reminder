#include<stdio.h>
#include<string.h>
char s[150000];
int main()
{
    int n,str_len,j_judge,o_judge;
    scanf("%d\n",&n);
    for (int i = 0; i< n; i++ )
    {
        gets(s);
        str_len = strlen(s);
        j_judge = 1;
        o_judge = 1;
        //if (str_len & 1)
        //{
            for (int j = 0; j < str_len/2; j++ )
            {
                if (s[j] != s[str_len-1-j])
                {
                    j_judge = 0;
                }
                if (s[j] == s[str_len-1-j])
                {
                    o_judge = 0;
                }
            }
            /*if (j_judge)
            {
                printf("Wingardium Leviosa\n");
            }
            else
            {
                printf("The spell fails\n");
            }*/
        //}
        if (str_len & 1)
        {
            if (j_judge)
            {
                printf("Wingardium Leviosa\n");
            }
            else
            {
                printf("The spell fails\n");
            }
        }
        else
        {
            if (o_judge)
            {
                printf("Wingardium Leviosa\n");
            }
            else
            {
                printf("The spell fails\n");
            }
        }

    }
    return 0;
}