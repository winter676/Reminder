#include<stdio.h>
#include<math.h>
int is_prime(long long num);
int main()
{
    int judge = 1;
    long long num;
    double numSqrt;
    while (scanf("%lld",&num) != EOF){
        judge = 1;
        if (is_prime(num)){
            printf("Not otter's type!\n");
        }
        else {
            numSqrt = sqrt(num);
            for (long long i = 2; i <= numSqrt; i ++){
                if (is_prime(i) && num % i == 0 && is_prime(num/i)){
                    printf("%lld %lld\n",i,num/i);
                    judge = 0;
                    break;
                }
            }
            if (judge){
                printf("Not otter's type!\n");
            }
        }
    }
}


int is_prime(long long num)
{
    if (num <= 1){
        return 0;
    }
    if (num == 2){
        return 1;
    }
    if (num % 2 == 0){
        return 0;
    }
    for (int i = 3; i <= sqrt(num); i += 2){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}