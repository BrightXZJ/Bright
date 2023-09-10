#include<stdio.h> 
int main (){
	int a,b,c;
	//a表示现在的位置
	//b表示目的地
	//c表示电梯位置 
	scanf("%d%d%d",&a,&b,&c);
	int time=0;
	printf("%d %d 0\n",c,time);//输出初始位置
	time=abs(a-c);
	printf("%d %d 1\n",a,time);
	time+=abs(b-a);
	printf("%d %d 0",b,time);
	return 0;
} 
