#include<stdio.h>

int main()
{
    int people[20];
    int total = 20;
    int current = 0;
    int count = 0;

    for (int i = 0; i < 20; i++ ){
        people[i] = 0;
    }

    while (total > 1){
        if (people[current] == 0){
            count++;
            if (count == 2){
                people[current] = 1;
                count = 0;
                total --;
            }
        }
        current = (current+1)%20;
    }

    for (int i = 0; i < 20; i++ ){
        if (people[i] == 0){
            printf("%d",i+1);
            break;
        }
    }

    return 0;
}