#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    double X[1500],Y[1500],sum_x = 0,sum_y = 0,sum2_x = 0,sum2_y = 0,sum_xy = 0,X_,Y_,result;
    scanf("%d",&n);
    for (int i = 0; i < n; i++ ){
        scanf("%lf",&X[i]);
        sum_x += X[i];
        sum2_x += (X[i]*X[i]);
    }
    for (int i = 0; i < n; i++ ){
        scanf("%lf",&Y[i]);
        sum_y += Y[i];
        sum2_y += (Y[i]*Y[i]);
    }
    X_ = sum_x/n;
    Y_ = sum_y/n;
    for (int i = 0; i < n; i++ ){
        sum_xy += (X[i]*Y[i]);
    }
    result = (sum_xy-(n*X_*Y_))/(sqrt((sum2_x-n*X_*X_)*(sum2_y-n*Y_*Y_)));
    printf("%.2f\n",result);
    return 0;

}