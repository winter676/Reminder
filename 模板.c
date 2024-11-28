// 基本结构
#include<stdio.h>
#include<math.h>
int main()
{
    return 0;
}

//辗转相除法求公因数
long long gcd(long long a,long long b)
{
    long long _gcd,temp; //求正整数a和b的最大公因数

    while(b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    _gcd=a;
    return _gcd;
}

//斐波那契数列
long long f(int x)
{
    if (x == 0)
    {
        return a;
    }
    else if (x == 1)
    {
        return a + b;
        else
    }
    return f(x - 1) + f(x - 2);
}

//递推斐波那契数列
#define N 100
unsigned long long F[101] = {0, 1};
void fib_loop(int n)
{
    int i;
    for(i=2; i<=N; i++)
    F[i] = F[i-1] + F[i-2];
}



//阶乘
unsigned long long f(int n)
{
    if ( n <= 1 )
    {
        return 1;
    
    }
    return ( n * f(n-1) );
}

//组合数
int comb_num(int m, int n)
{
    if (n == 0 || m == n)
    {
        return 1;
    }
    if ( m < n )
    {
        return 0;
    }
    if ( n == 1 )
    {
        return m;
    }
    return comb_num(m-1, n) + comb_num(m-1, n-1);
}


// 汉诺塔
void hanoi(int n, char from, char via, char to)
{
    if (n == 1)
    {
        move(n, from, to);
        return;
    }
    hanoi(n - 1, from, to, via); // 递归：挪上面的n-1个盘子
    move(n, from, to); // 移动第n个盘子
    hanoi(n - 1, via, from, to); // 递归：挪n-1个盘子
}
void move(int i, char from, char to)
{
    printf("Distk %d, %c --> %c\n", i, from, to);
}


//  随机数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int point;
    srand( time( 0 ) );
    point = 1 + rand()%6;
    printf("Dice is: %d\n", point);
    printf((point%2) ? "lose": "win");//单数输，双数赢
    return 0;
}

//清空脏数据
int a;
char ch;
printf("\ninput a score 0~100:\n");
printf("(input other char to go on)\n");
while(scanf("%d", &a) == 0 || a < 0 || a > 100)
{
    printf("invalid input!\n\n");
    while(scanf("%c", &ch) == 1 && ch != '\n');
}
printf("\nGood job! Valid input %d!\n", a);


//冒泡排序
void bubbleSort(int a[], int n)
{
    int i, j, hold;
    for(i=1; i<n; i++) { //扫描轮数
        for(j=0; j<n-i; j++) {
            if(a[j] > a[j+1]) {
                hold = a[j];
                a[j] = a[j+1];
                a[j+1] = hold;
            }
        }
    }
}


//优化的冒泡
void optiBubSort(int a[], int n)
{
    int i, j, hold, swapFlag;
    for(i=1; i<n; i++) //扫描轮数
    {
        swapFlag = 0;
        for(j=0; j<n-i; j++) //某轮扫描
        {
            if(a[j] > a[j+1])
            {
                swapFlag = 1; // flag1
                hold = a[j];
                a[j] = a[j+1];
                a[j+1] = hold;
            }
        }
        if(swapFlag == 0) // flag0
            break;
    }
}