#include<stdio.h>
#include<stdlib.h>
struct bit{
    int weight;
    int num;
}input[550000],temp;

int getWeight(int num);


int cmp(const void *a ,const void *b);

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++ ){
        scanf("%d",&input[i].num);
        input[i].weight = getWeight(input[i].num);
    }
    qsort(input->weight,n,sizeof(int),cmp);
    for (int i = 0; i < n -1 ; i++ ){
        int k = i;
        for (int j = i+1; j < n; j++ ){
            if (input[j].weight > input[k].weight){
                k = j;
            }
            if (input[j].weight == input[k].weight){
                if (input[j].num > input[k].num){
                    k = j;
                }
            }
        }
        temp = input[k];
        input[k] = input[i];
        input[i] = temp;
    }
    for (int i = 0; i < n; i++ ){
        printf("%d\n",input[i].num);
    }
    return 0;

}


int getWeight(int num)
{
    int sum = 0;
    for (int i = 0; i < 32; i++ ){
        sum += ((i+1)*((num>>i)&1));
    }
    return sum;
}

int cmp(const void *a ,const void *b)
{
	return *(int *)b - *(int *)a ;
}