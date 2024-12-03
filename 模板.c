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



//排序算法cmp函数；
//从小到大：
int cmp(const void *a ,const void *b)
{
	return *(int *)a - *(int *)b ;			//从小到大排序，不能写成 return a < b 这种形式
}

//从大到小
int cmp(const void *a ,const void *b)
{
	return *(int *)b - *(int *)a ;
}



//二分算法
//左闭右闭
int search(int nums[], int size, int target) //nums是数组，size是数组的大小，target是需要查找的值
{
    int left = 0;
    int right = size - 1;	// 定义了target在左闭右闭的区间内，[left, right]
    while (left <= right) {	//当left == right时，区间[left, right]仍然有效
        int middle = left + ((right - left) / 2);//等同于 (left + right) / 2，防止溢出
        if (nums[middle] > target) {
            right = middle - 1;	//target在左区间，所以[left, middle - 1]
        } else if (nums[middle] < target) {
            left = middle + 1;	//target在右区间，所以[middle + 1, right]
        } else {	//既不在左边，也不在右边，那就是找到答案了
            return middle;
        }
    }
    //没有找到目标值
    return -1;
}

//左闭右开
int search(int nums[], int size, int target)
{
	int left = 0;
	int right = size; //定义target在左闭右开的区间里，即[left, right)
	while (left < right) {	//因为left = right的时候，在[left, right)区间上无意义
		int middle = left + ((right - left) / 2);
		if (nums[middle] > target) {
			right = middle; //target 在左区间，在[left, middle)中 
		} else if (nums[middle] < target) {
			left = middle + 1;
		} else {
			return middle;
		}
	} 
    // 没找到就返回-1
	return -1;
}


//进制的转换
int char_to_num(char ch) //字符串到数字
{
    if(ch>='0' && ch<='9')
        return ch-'0';  /*将数字字符转换成数字*/
    else
        return ch-'A'+10;  /*将字母字符转换成数字*/
}


char num_to_char(int num)//数字到数字
{
    if(num>=0 && num<=9)
        return (char)('0'+num-0);  /*将0~9之间的数字转换成字符*/
    else
        return (char)('A'+num-10);  /*将大于10的数字转换成字符*/
}


long source_to_decimal(char temp[], int source) //任意进制数转换为10进制
{
    long decimal_num = 0;  /*存储展开之后的和*/
    int length;
    int i;
    for( i=0; temp[i]!='\0'; i++ );
    length=i;
    for( i=0; i<=length-1; i++ )  /*累加*/
        decimal_num = (decimal_num*source) + char_to_num(temp[i]);
    return decimal_num;
}

int decimal_to_object(char temp[], long decimal_num, int object)
{
    int i=0;
    while(decimal_num)
    {
        temp[i] = num_to_char(decimal_num % object);  /*求出余数并转换为字符*/
        decimal_num = decimal_num / object;  /*用十进制数除以基数*/
        i++;
    }
    temp[i]='\0';
    return i;
}
