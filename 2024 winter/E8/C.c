#include<stdio.h>

unsigned int justDoItOne(unsigned int a,unsigned int option,unsigned int objectOne);
unsigned int justDoItTwo(unsigned int a,unsigned int option,unsigned int objectOne,unsigned int objectTwo);
unsigned int swap_bits(unsigned int num,unsigned int pos1,unsigned int pos2);
int main()
{
    unsigned int T,a,t,option,objectOne,objectTwo;
    scanf("%u",&T);
    for (unsigned int k = 0u; k < T; k++){
        scanf("%u%u",&a,&t);
        for (unsigned int i = 0u; i < t; i++ ){
            scanf("%u",&option);
            if (option == 1u || option == 5u){
                scanf("%u%u",&objectOne,&objectTwo);
                a = justDoItTwo(a,option,objectOne,objectTwo);
            }
            else{
                scanf("%u",&objectOne);
                a = justDoItOne(a,option,objectOne);
            }
        }
        printf("%u\n",a);
    }
}


unsigned int justDoItOne(unsigned int a,unsigned int option,unsigned int objectOne)
{
    unsigned int result = a;
    if (option == 2u){
        result = (a ^ (1u<<objectOne));
    }
    else if (option == 3u){
        result = (a | (1u<<objectOne));
    }
    else if (option == 4u){
        result = (a & ~(1u<<objectOne));
    }
    return result;
}


unsigned int justDoItTwo(unsigned int a,unsigned int option,unsigned int objectOne,unsigned int objectTwo)
{
    unsigned int result = a;
    if (option == 1u){
        result = swap_bits(a,objectOne,objectTwo);
    }
    else if (option == 5u){
        for (unsigned int i = 0u; i < (objectTwo-objectOne+1u)/2; i++ ){
            a = swap_bits(a,objectOne+i,objectTwo-i);
        }
        result = a;
    }
    return result;
}


unsigned int swap_bits(unsigned int num,unsigned int pos1,unsigned int pos2) 
{
    unsigned int bit1 = (num >> pos1) & 1u;
    unsigned int bit2 = (num >> pos2) & 1u;
    if (bit1 != bit2) {
        unsigned int mask = (1u << pos1) | (1u << pos2);
        num ^= mask;
    }
    return num;
}