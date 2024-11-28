#include<stdio.h>
#include<math.h>
void formatarry(int a[],int n,int i);
int main()
{
    int sign[20000],front[20000],behind[20000],num = 1,num2 = 0;
    char temp,age;
    formatarry(front,20000,1);
    formatarry(behind,2000,0);
    //读取第一项
    scanf("f(x)=%c",&temp);
    if (temp == '-'){
        sign[0] = -1;
        scanf("%d",front[0]);
    }
    else if (temp == 'x'){
        sign[0] = 1;
        front[0] = 1;
    }
    else{
        sign[0] = 1;
        front[0] = (int)temp-(int)'0';
    }

    //其余项数
    while (scanf("%c",&temp) != EOF){
        if (temp == '+'){
            sign[num] = 1;
            scanf("%d",&front[num]);
            num++;
        }
        if (temp == '-')
            sign[num] = -1;
            scanf("%d",&front[num]);
            num++;
        }
        if (temp == '^'){
            scanf("%d",&behind[num2]);
            num2++;
        }
        if (age == 'x' && (temp == '+' || temp == '-')){
            behind[num2] = 1;
            num2++;
        }
        age = temp;
    }
    if (age == '+'){
        behind[num-2] = 1;
    }

    return 0;
}

void formatarry(int a[],int n,int i){
    for (int j = 0; j < n; j++ ) {
        a[j] = i;
    }
}