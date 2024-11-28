#include<stdio.h>
#include<math.h>

double Softplus(double x);
int main()
{
    double x;
    while (scanf("%lf",&x) != EOF){
        printf("%.4f\n",Softplus(x));
    }
}


double Softplus(double x)
{
    return log(1 + exp(x));
}