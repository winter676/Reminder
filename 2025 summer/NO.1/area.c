#include<stdio.h>

int max(int a,int b);
int min(int a,int b);
int intersect(int A1,int A2,int B1,int B2);

int main()
{
    int Ax1,Ay1,Ax2,Ay2,Bx1,By1,Bx2,By2,xintersect,yintersect;
    scanf("%d%d%d%d",&Ax1,&Ay1,&Ax2,&Ay2);
    scanf("%d%d%d%d",&Bx1,&By1,&Bx2,&By2);
    xintersect = intersect(Ax1,Ax2,Bx1,Bx2);
    yintersect = intersect(Ay1,Ay2,By1,By2);
    printf("%d\n",xintersect*yintersect);
    return 0;
}

int intersect(int A1,int A2, int B1,int B2)
{
    int MAX_A,MIN_A,MAX_B,MIN_B,xyintersect;
    MAX_A = max(A1,A2);
    MIN_A = min(A1,A2);
    MAX_B = max(B1,B2);
    MIN_B = min(B1,B2);
    xyintersect = min(MAX_A,MAX_B)-max(MIN_A,MIN_B);
    if (xyintersect <= 0){
        return 0;
    }
    else{
        return xyintersect;
    }
}

int max(int a,int b)
{
    if (a > b){
        return a;
    }
    return b;
}

int min(int a,int b)
{
    if (a < b){
        return a;
    }
    return b;
}