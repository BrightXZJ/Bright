#include<stdio.h> 
int main (){
	int a,b,c;
	//a��ʾ���ڵ�λ��
	//b��ʾĿ�ĵ�
	//c��ʾ����λ�� 
	scanf("%d%d%d",&a,&b,&c);
	int time=0;
	printf("%d %d 0\n",c,time);//�����ʼλ��
	time=abs(a-c);
	printf("%d %d 1\n",a,time);
	time+=abs(b-a);
	printf("%d %d 0",b,time);
	return 0;
} 
