/*
思路为牺牲空间换取时间
大胆设变量
最后在进行代码优化减少变量数量
*/
#include<stdio.h>
#include<string.h>
#define Maxpeople 4
#define MAX 10
struct _Pas{//记录每一个乘客的基本信息 
	int desfloor;//目标楼层
	int startfloor;//起点 
   int ud;//上楼或者下楼
}pas[22];//最多每层一个人，也就是开20数组应该足够 st
struct _Ele{//使用一个struct来代替电梯的状态 
	int uod;//up or down .1 for up .2 for down
	int num;//电梯的人数
   int time;//记录电梯运行时间
	int nowfloor;//电梯所在楼层 
   int dateele[5];//用于记录电梯上四个人的目的地
}ele;
int flor[15];//记录每一层的人的编号
int N;//记录上楼的人数
int Min=100,Max=-100;
//Min用来储存最小上楼楼层，Max用来标记最高下楼楼层
int numup,numdown;  //记录上楼下楼的人数
int laststop;//一个变量用于记录要下人的楼层

void findup(){    //用于当前最低上楼楼层被覆盖后，寻找次高上楼楼层
   int x=Min+1;
   while(pas[flor[x]].ud!=1) {x++;}
   Min=x;
   return ;
}
void finddown(){    //用于当前最高下楼楼层被覆盖后，寻找次低下楼楼层
   int x=Max-1;
   while(pas[flor[x]].ud!=2) {x--;}
   Max=x;
   return ;
}
void upele(int a){//执行上人操作
   ele.num++;//电梯人数增加
   ele.time+=abs(ele.nowfloor-a);//更新电梯时间
   ele.nowfloor=a;//更新电梯所在楼层
   if(ele.uod==1){
      numup--;
   }else{
      numdown--;
   }
   for(int i=1;i<=Maxpeople;i++){
      if(ele.dateele[i]==0){
         ele.dateele[i]=flor[a];
         break;
      }
   } 
   flor[a]=-1;//这一层的人已经上电梯
   return ;
}
void downele(int a){//执行下人操作
   ele.time+=abs(ele.nowfloor-a);//更新电梯时间
   for(int i=1;i<=Maxpeople;i++){
      if(pas[ele.dateele[i]].desfloor==a){
         ele.num--;//电梯人数减少
         ele.dateele[i]==0;
      }
   }
   printf("%d %d %d",ele.nowfloor,ele.time,ele.num);
   return ;
}
void reupflor(int a){//用来执行上人的过程
   if(pas[flor[a]].ud==ele.uod&&ele.num<Maxpeople){
      upele(a);
      printf("%d %d %d\n",ele.nowfloor,ele.time,ele.num);
   }else if(ele.num==Maxpeople){
      break;
   }
}
void redownflor(int a){
   if(a==laststop) downele(a);
}
int main (){
   scanf("%d",&N);//输入上下楼的人数
   memset(flor,-1,sizeof(flor));
   for(int i=1;i<=N;i++){
   scanf("%d%d",&pas[i].startfloor,&pas[i].desfloor);
   //输入每个人的起点和终点
   flor[pas[i].startfloor]=i;
   if(pas[i].desfloor<pas[i].startfloor) {pas[i].ud=2;numdown++;}
   //标注这个人是上楼还是下楼//1代表为上楼，2代表下楼
   else {pas[i].ud=1;numup++;}
   if(pas[i].startfloor<Min&&pas[i].ud==1) Min=pas[i].startfloor;
   if(pas[i].startfloor>Max&&pas[i].ud==2) Max=pas[i].startfloor;
   //进行最低和最高楼层的赋值
   }
   if(flor[1]!=-1) printf("1 0 0\n");  else {printf("1 0 1\n");flor[1]=-1;ele.num++;}//电梯启动时
	ele.uod=1;
   while(ele.num>0||numup>0||numdown>0){
      if()
      reupflor(Min);
   }
   return 0;
} 