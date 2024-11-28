#include<stdio.h>
#include<stdlib.h>
struct student
{
    int a;
    int b;
}stu[510000];

int compare(const void *a, const void *b)
{
    struct student *studentA = (struct student *)a;
    struct student *studentB = (struct student *)b;

    if (studentA->a != studentB->a)
    {
        return studentB->a - studentA->a;
    }
    else
    {
        return studentA->b - studentB->b;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++ ){
        scanf("%d%d",&stu[i].a,&stu[i].b);
    }
    qsort(stu, n, sizeof(struct student), compare);
    for (int i = 0; i < n; i++){
        printf("%d: %d %d\n",i+1,stu[i].a,stu[i].b);
    }

}