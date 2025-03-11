#include<stdio.h>
#include<math.h>

long long turn(long long num);
int isPrime(long long num);
int isTurnPrime(long long num);

int main()
{
    long long input;
    scanf("%lld",&input);
    if (isTurnPrime(input)){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    return 0;
}

long long turn(long long num)
{
    long long output = 0;
    while(num){
        output = output*10+num%10;
        num /= 10;
    }
    return output;
}

int isPrime(long long num)
{
    double max = sqrt(num);
    for (int i = 2; i <= max; i++ ){
        if (!(num % i)){
            return 0;
        }
    }
    return 1;
}


int isTurnPrime(long long num)
{
    long long turnNum;
    if (!isPrime(num)){
        return 0;
    }
    else{
        turnNum = turn(num);
        if (isPrime(turnNum)){
            return 1;
        }
        return 0;
    }
}