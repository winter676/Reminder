#include<stdio.h>
#include<stdlib.h>

typedef struct line{
    int x1;
    int y1;
    int x2;
    int y2;
}LINE;

void ToTarget(int *a,int n,int target);
void input(int *n,LINE *a);
int maxLine(int num,int *isUsed,LINE *L,LINE *start);
int cmp(const void *a,const void *b);


int main()
{
    LINE L[150],start;
    int num,isUsed[150],max;

    input(&num,L);
    ToTarget(isUsed,150,0);
    qsort(L,num,sizeof(L[0]),cmp);

    max = maxLine(num,isUsed,L,&start);

    printf("%d %d %d\n",max,start.x1,start.y1);

    return 0;
}


void ToTarget(int *a,int n,int target)
{
    for (int i = 0; i < n; i++ ){
        a[i] = target;
    }
    return;
}

void input(int *n,LINE *a)
{
    scanf("%d",n);
    for (int i = 0; i < *n; i++ ){
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
    return;
}

int maxLine(int num,int *isUsed,LINE *L,LINE *start)
{
    int right = 1,current,max = 0,currentnum=0;
    for (int i = 0; i < num; i++ ){
        if (isUsed[i]) continue;
        else{
            currentnum = 1;
            current = i;
            isUsed[i] = 1;
            right = 1;
            while (right){
                right = 0;
                for (int j = 0; j < num; j++ ){
                    if (isUsed[j]) continue;
                    else{
                        if (L[j].x1 == L[current].x2 && L[j].y1 == L[current].y2){
                            isUsed[j] = 1;
                            current = j;
                            right = 1;
                            currentnum++;
                            break;
                        }
                    }
                }
            }
            if (currentnum > max){
                max = currentnum;
                *start = L[i];
            }
        }
    }
    return max;

}


int cmp(const void *a,const void *b)
{
    int num1,num2;
    num1 = (*(LINE *)a).x1;
    num2 = (*(LINE *)b).x1;
    return num1 - num2;
}