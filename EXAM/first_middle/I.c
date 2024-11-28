#include<stdio.h>
#include<math.h>
void hanoi(int n, char from, char via, char to);
void move(int i, char from, char to);
int main()
{

    return 0;
}


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