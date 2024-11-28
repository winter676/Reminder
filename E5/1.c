#include <stdio.h>
#define M 1000000
int x[M];
int main()
{
	int k = 0;
	for (int i = 1;i < 1000000;i ++)
	{
		int trump = i;
		while (trump != 0)
		{
			if (trump % 10 == 7)
			{
				x[k] = i;
				k ++;
				break;
			}
			trump = trump / 10;
		}
	}
	int a,b,sum = 0,p = 0;
	scanf("%d%d",&a,&b);
	for (int i = a;i <= b;i ++)
	{
		p = 0;
		for (int j = 0;j < k;j ++)
		{
			if (i % x[j] == 0)
			{
				p = 1;
				break;
			}
		}
		if (p == 0)
		{
			sum ++;
		}
	}
	printf("%d",sum);
	return 0;
}