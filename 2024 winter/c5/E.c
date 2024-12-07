#include<stdio.h>
#include<math.h>
void hanoi(int n,char from, char via,char to);
void move(int i,char from ,char to);
int main()
{
    int n;
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}

void hanoi(int n,char from, char via,char to)
{
    if (n == 1)
    {
        move(n,from,to);
        return;
    }
    hanoi(n-1,from,to,via);
    move(n,from,to);
    hanoi(n-1,via,from,to);
}

void move(int i,char from ,char to)
{
    printf("Moca move otter %d from queue %c to queue %c\n",i,from,to);
}