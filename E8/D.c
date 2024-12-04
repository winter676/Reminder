#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Move {
    long long list;
    int isUsed;
};

long long findMinIndex(struct Move moving[],long long n,long long m);

int main()
{
    struct Move moving[1000];
    long long n,m,sum = 0,min = 0,minIndex = 0,i;

    scanf("%lld%lld",&n,&m);
    for ( i = 0; i < n; i++ ){
        moving[i].isUsed = 0;
        scanf("%lld",&moving[i].list);
    }
    for ( i = 0; i < n; i++ ){
        minIndex = findMinIndex(moving,n,m);
        long long value = moving[minIndex].list-m;
        long long valueAbs = llabs(value);
        sum += valueAbs;
        m += value;
        printf("%lld ",m);
        moving[minIndex].isUsed = 1;
    }
    printf("\n%lld\n",sum);
    return 0;
}


long long findMinIndex(struct Move moving[],long long n,long long m)
{
    long long min = -1,i;
    long long minIndex = -1;

    for ( i =  0; i < n; i++ ){
        if (moving[i].isUsed){
            continue;
        }
        long long value = llabs(moving[i].list - m);
        if (min == -1 || value < min  || (value == min && moving[i].list < moving[minIndex].list)){
            min = value;
            minIndex = i;
        }
    }
    return minIndex;
}