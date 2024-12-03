/*
	Author: Protoss
	
	使用方法：
	INT_LEN 是可以存储的最大位数，建议多开一些，否则会出错。
	每当定义 BigInteger 变量时，请注意调用 Biginteger_Init 进行初始化，否则可能会出错。建议定义全局变量而不是局部变量。
	不要尝试直接更改变量中任何成员的值，请使用函数间接更改。
	实现了很多常用的函数，下面是函数、参数及功能：

	void BigInteger_Init(BigInteger *this);		： 初始化 this 指向的变量，必须在定义后、使用前调用。不可重复调用。
	void BigInteger_Del(BigInteger *this);		： 释放 this 指向的变量，防止内存泄漏。变量使用结束时调用此函数。不可重复调用。
	void BigInteger_Check(BigInteger *this);	： 维护 this 指向变量的存储，将其转化为正确的存储格式。

	void BigInteger_Copy(BigInteger *dest,BigInteger *src)					： 等价于 *dest=*src;
	void BigInteger_Clear(BigInteger *this);								： 等价于 *this=0;
	void BigInteger_GiveSigned(BigInteger *this,long long num);				： 等价于 *this=(BigInteger)num;
	void BigInteger_GiveUnsigned(BigInteger *this,unsigned long long num);	： 等价于 *this=(BigInteger)num;
	long long BigInteger_toLL(BigInteger *this);							： 等价于 (long long)*this;
	int BigInteger_Input(BigInteger *this);									： 读取 this 指向的变量，返回值与 scanf 相同。
	void BigInteger_Output(BigInteger *this);								： 打印 this 指向的变量。

	int BigInteger_Compare(BigInteger *a,BigInteger *b);	： 比较 *a 和 *b 的大小，返回值与 strcmp 类似。
	void BigInteger_Add(BigInteger *a,BigInteger *b);		： 等价于 *a+=*b;
	void BigInteger_Subtract(BigInteger *a,BigInteger *b);	： 等价于 *a-=*b;
	void BigInteger_Multiply(BigInteger *a,BigInteger *b);	： 等价于 *a*=*b;
	void BigInteger_Divide(BigInteger *a,BigInteger *b);	： 等价于 *a/=*b; ，向 0 取整
	void BigInteger_Modulo(BigInteger *a,BigInteger *b);	： 类似于 *a%=*b; ，但结果恒非负

	注 1 ：为避免混淆，所有 BigInteger 类型的参数都是指针形式。
	注 2 ：第 33 行到第 292 行是模板，后续 main() 函数内举例了一些用法，此代码可以 AC 2024 年《程序设计基础》课程 E8 E 题。
	注 3 ：作者能力有限，部分函数性能较差，望理解。
*/
#ifndef __BIGINTEGER__
#define __BIGINTEGER__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define INT_LEN 100010

typedef struct{
	int *s;
	int len;
	int sign;
	int isInit;
}BigInteger;

void BigInteger_Init(BigInteger*);
void BigInteger_Del(BigInteger*);
void BigInteger_Check(BigInteger*);

void BigInteger_Init(BigInteger *this){
	this->s=(int*)calloc(INT_LEN,sizeof(int));
	this->len=0;
	this->sign=0;
	this->isInit=1;
}
void BigInteger_Del(BigInteger *this){
	if ( this->isInit==0 )
		return;
	free(this->s);
	this->isInit=0;
}
void BigInteger_Check(BigInteger *this){
	for ( int i=0 ; i<this->len ; i++ ){
		if ( this->s[i]<0 ){
			this->s[i+1]+=this->s[i]/10;
			this->s[i]%=10;
			if ( this->s[i]<0 ){
				this->s[i+1]--;
				this->s[i]+=10;
			}
		}
		else if ( this->s[i]>9 ){
			this->s[i+1]+=this->s[i]/10;
			this->s[i]%=10;
		}
	}
	while ( this->s[this->len]>0 ){
		this->s[this->len+1]=this->s[this->len]/10;
		this->s[this->len]%=10;
		this->len++;
	}
	if ( this->s[this->len]<0 ){
		this->sign^=1;
		this->s[++this->len]=0;
		for ( int i=0 ; i<this->len ; i++ )
			this->s[i]=-this->s[i];
		BigInteger_Check(this);
	}
	while ( this->s[this->len-1]==0 && this->len>=1 )
		this->len--;
	if ( this->len==0 )
		this->sign=0;
}

void BigInteger_Copy(BigInteger*,BigInteger*);
void BigInteger_Clear(BigInteger*);
void BigInteger_GiveSigned(BigInteger*,long long);
void BigInteger_GiveUnsigned(BigInteger*,unsigned long long);
long long BigInteger_toLL(BigInteger*);
int BigInteger_Input(BigInteger*);
void BigInteger_Output(BigInteger*);

void BigInteger_Copy(BigInteger *a,BigInteger *b){
	if ( a->isInit==0 )
		BigInteger_Init(a);
	a->len=b->len;
	a->sign=b->sign;
	memcpy(a->s,b->s,sizeof(int)*(b->len+1));
	a->s[a->len]=0;
}
void BigInteger_Clear(BigInteger *this){
	if ( this->isInit==0 )
		BigInteger_Init(this);
	else
		this->len=this->sign=this->s[0]=0;
}
void BigInteger_GiveSigned(BigInteger *this,long long x){
	if ( x>0 )
		BigInteger_GiveUnsigned(this,x);
	else{
		unsigned long long ux=-x;
		BigInteger_GiveUnsigned(this,ux);
		this->sign=1;
	}
}
void BigInteger_GiveUnsigned(BigInteger *this,unsigned long long x){
	BigInteger_Clear(this);
	while ( x ){
		this->s[this->len++]=x%10;
		x/=10;
	}
	this->s[this->len]=0;
}
long long BigInteger_toLL(BigInteger *this){
	BigInteger_Check(this);
	long long ret=0;
	for ( int i=this->len-1 ; i>=0 ; i-- )
		ret=ret*10+this->s[i];
	if ( this->sign )
		ret=-ret;
	return ret;
}
int BigInteger_Input(BigInteger *this){
	BigInteger_Clear(this);
	int te,tmp=0;
	char r='+';
	scanf(" %1[+-]",&r);
	if ( r=='-' )
		this->sign=1;
	while ( (te=scanf("%1[0-9]",&r))==1 && (tmp=1) )
		this->s[this->len++]=r-'0';
	this->s[this->len]=0;
	if ( tmp==0 )
		return te;
	for ( int i=0,j=this->len-1 ; i<j ; i++,j-- ){
		r=this->s[i];
		this->s[i]=this->s[j];
		this->s[j]=r;
	}
	return 1;
}
void BigInteger_Output(BigInteger *this){
	BigInteger_Check(this);
	if ( this->len==0 ){
		putchar('0');
		return;
	}
	if ( this->sign )
		putchar('-');
	for ( int i=this->len-1 ; i>=0 ; i-- )
		putchar(this->s[i]+'0');
}

int BigInteger_Compare(BigInteger*,BigInteger*);
void BigInteger_Add(BigInteger*,BigInteger*);
void BigInteger_Subtract(BigInteger*,BigInteger*);
void BigInteger_Multiply(BigInteger*,BigInteger*);
void BigInteger_Divide(BigInteger*,BigInteger*);
void BigInteger_Modulo(BigInteger*,BigInteger*);

int BigInteger_Compare(BigInteger *a,BigInteger *b){
	BigInteger_Check(a);
	BigInteger_Check(b);
	if ( a->sign!=b->sign )
		return a->sign-b->sign;
	if ( a->sign==0 ){
		if ( a->len!=b->len )
			return a->len-b->len;
		for ( int i=a->len-1 ; i>=0 ; i-- )
			if ( a->s[i]!=b->s[i] )
				return a->s[i]-b->s[i];
		return 0;
	}
	else{
		if ( a->len!=b->len )
			return b->len-a->len;
		for ( int i=a->len-1 ; i>=0 ; i-- )
			if ( a->s[i]!=b->s[i] )
				return b->s[i]-a->s[i];
		return 0;
	}
}
void BigInteger_Add(BigInteger *a,BigInteger *b){
	if ( a->len < b->len ){
		for ( int i=a->len ; i<=b->len ; i++ )
			a->s[i]=0;
		b->s[b->len]=0;
		a->len=b->len;
	}
	else
		a->s[a->len]=0;
	if ( a->sign==b->sign )
		for ( int i=0 ; i<b->len ; i++ )
			a->s[i]+=b->s[i];
	else
		for ( int i=0 ; i<b->len ; i++ )
			a->s[i]-=b->s[i];
	BigInteger_Check(a);
}
void BigInteger_Subtract(BigInteger *a,BigInteger *b){
	b->sign^=1;
	BigInteger_Add(a,b);
	b->sign^=1;
}
void BigInteger_Multiply(BigInteger *a,BigInteger *b){
	a->sign^=b->sign;
	int *tmp=(int*)calloc(INT_LEN,sizeof(int));
	for ( int i=0 ; i<a->len ; i++ )
		for ( int j=0 ; j<b->len ; j++ )
			tmp[i+j]+=a->s[i]*b->s[j];
	free(a->s);
	a->s=tmp;
	a->len+=b->len;
	BigInteger_Check(a);
}
void BigInteger_Divide(BigInteger *a,BigInteger *b){
	if ( b->len==0 )
		return;
	int a_sign=a->sign,b_sign=b->sign;
	a->sign=b->sign=0;
	if ( BigInteger_Compare(a,b)<0 ){
		BigInteger_Clear(a);
		b->sign=b_sign;
		return;
	}
	int delta=a->len-b->len;
	BigInteger bt,at;
	BigInteger_Init(&bt);
	BigInteger_Init(&at);
	BigInteger_Copy(&bt,b);
	BigInteger_Copy(&at,a);
	BigInteger_Clear(a);
	a->len=delta+1;
	for ( int i=0 ; i<=a->len ; i++ )
		a->s[i]=0;
	for ( int i=bt.len-1 ; i>=0 ; i-- )
		bt.s[i+delta]=bt.s[i];
	for ( int i=delta-1 ; i>=0 ; i-- )
		bt.s[i]=0;
	bt.len+=delta;
	while ( delta>=0 ){
		if ( BigInteger_Compare(&at,&bt)<0 ){
			delta--;
			for ( int i=0 ; i<bt.len ; i++ )
				bt.s[i]=bt.s[i+1];
			bt.s[--bt.len]=0;
			continue;
		}
		BigInteger_Subtract(&at,&bt);
		a->s[delta]++;
	}
	BigInteger_Check(a);
	a->sign=a_sign^b_sign;
	b->sign=b_sign;
	BigInteger_Del(&bt);
	BigInteger_Del(&at);
}
void BigInteger_Modulo(BigInteger *a,BigInteger *b){
	if ( b->len==0 )
		return;
	BigInteger at;
	BigInteger_Init(&at);
	BigInteger_Copy(&at,a);
	BigInteger_Divide(&at,b);
	BigInteger_Multiply(&at,b);
	BigInteger_Subtract(a,&at);
	BigInteger_Del(&at);
}
#endif

int main(){
	BigInteger a,b;
	BigInteger_Init(&a);// 初始化
	BigInteger_Init(&b);

	BigInteger_Input(&a);
	BigInteger_Input(&b);// 读取 b 时会将 + 自动当作正号处理
	BigInteger_Add(&a,&b);
	BigInteger_Output(&a);
	
	BigInteger_Del(&a);// 结束占用，释放内存
	BigInteger_Del(&b);
	return 0;
}