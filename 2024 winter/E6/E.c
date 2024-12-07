#include<stdio.h>
#include<math.h>
int Moca[10][10],start[10][10];
int checkStart();
int checkhang();
int checklie();
int checkgong();
void optiBubSort(int a[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    for (int k = 0; k < t; k++ )
    {
        for (int i = 0; i < 9; i++ )
        {
            for (int j = 0; j < 9; j++ )
            {
                scanf("%d",&start[i][j]);
            }
        }
        for (int i = 0; i < 9; i++ )
        {
            for (int j = 0; j < 9; j++ )
            {
                scanf("%d",&Moca[i][j]);
            }
        }
     
        if (checkhang() && checklie() && checkgong() && checkStart())
        {
            printf("Moca finish this sudoku perfectly!\n");
        }
        else
        {
            printf("Moca is so careless!\n");
        }
    }
    return 0;
}

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
int checkStart()
{
    for (int i = 0; i < 9; i++ )
    {
        for (int j = 0; j < 9; j++ )
        {
            if (start[i][j] != 0)
            {
                if (start[i][j] != Moca[i][j])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int checkhang()
{
    int temp[9];
    for (int i = 0; i < 9; i++ )
    {
        for (int j = 0; j < 9; j++ )
        {
            temp[j] = Moca[i][j];
        }
        optiBubSort(temp,9); 
        for (int k = 0; k < 9; k++ )
        {
            if (temp[k] != (k+1))
            {
                return 0;
            }
        }
    }
    return 1;
}

int checklie()
{
    int temp[9];
    for (int i = 0; i < 9; i++ )
    {
        for (int j = 0; j < 9; j++ )
        { 
            temp[j] = Moca[j][i];
        }
        optiBubSort(temp,9);
        for (int k = 0; k < 9; k++ )
        {
            if (temp[k] != (k+1))
            {
                return 0;
            }
        }
    }
    return 1;
}

int checkgong()
{
    for (int i = 0; i < 3; i++ )
    {
        for (int j = 0; j < 3; j++ )
        {
            int k = 0,temp[9];
            for (int i1 = i*3; i1 < i*3+3;i1++ )
            {
                for(int j1 = j*3; j1 < j*3+3; j1++ )
                {
                    temp[k++] = Moca[i1][j1];
                }
            }
            optiBubSort(temp,9);
            for (int k1 = 0; k1 < 9; k1++ )
            {
                if (temp[k1] != (k1+1))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}