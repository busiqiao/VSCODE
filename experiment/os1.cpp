#include <stdio.h>
#define running 1 //用 running 表示进程处于运行态
#define aready 2 //用 aready 表示进程处于就绪态
#define blocking 3 //用 blocking 表示进程处于等待态
#define sometime 5 //用 sometime 表示时间片大小
#define n 10 //假定系统允许进程个数为 n

struct 
{
	int name;//进程标志符
	int status; //进程状态
	int ax,bx,cx,dx;//进程现场信息，通用寄存器内容
	int pc; //进程现场信息，程序计数器内容
	int psw;//进程现场信息，程序状态寄存器内容
	int next;//下一个进程控制块的位置
}pcbarea[n] ;//模拟进程控制块区域的数组

int PSW,AX,BX,CX,DX,PC,TIME; //模拟寄存器
int run;//定义指向正在运行进程的进程控制块的指针

struct
{ 
	int head;
	int tail; 
}ready;//定义就绪队列的头指针 head 和尾指针 tail

int pfree; //定义指向空闲进程控制块队列的指针

void sheduling()//进程调度函数
{ 
	int i ;
	if(ready.head==-1)//空闲进程控制块队列为空，退出
	{ 
		printf("无就绪进程\n"); 
		return;
	}
	
	i=ready.head;//就绪队列头指针赋给 i
	ready.head=pcbarea[ready.head].next;//就绪队列头指针后移
	
	if(ready.head==-1)
		ready.tail=-1; //就绪队列为空，修正尾指针 ready.tail
		
	pcbarea[i].status=running;//修改进程控制块状态
	TIME=sometime;//设置相对时钟寄存器
	
	//恢复该进程现场信息
	AX=pcbarea[run].ax;
	BX=pcbarea[run].bx; 
	CX=pcbarea[run].cx; 
	DX=pcbarea[run].dx;
	PC=pcbarea[run].pc;
	PSW=pcbarea[run].psw;
	run=i;//修改指向运行进程的指针
}//进程调度函数结束
void create(int x)//创建进程
{ 
	int i;
	if(pfree==-1)//空闲进程控制块队列为空
	{ 
		printf("无空闲进程控制块，进程创建失败\n");
		return;
	}
 	i=pfree;//取空闲进程控制块队列的第一个
	pfree=pcbarea[pfree].next;//pfree 后移
//填写该进程控制块内容:
	pcbarea[i].name=x;
	pcbarea[i].status=aready; 
	pcbarea[i].ax=x;
	pcbarea[i].bx=x; 
	pcbarea[i].cx=x;
	pcbarea[i].dx=x;
	pcbarea[i].pc=x;
	pcbarea[i].psw=x;
	if(ready.head!=-1) //就绪队列不空时，挂入就绪队列方式
	{ 
		pcbarea[ready.tail].next=i;
		ready.tail=i;
		pcbarea[ready.tail].next=-1;
	}
	else //就绪队列空时，挂入就绪队列方式
	{ 
		ready.head=i;
		ready.tail=i;
		pcbarea[ready.tail].next=-1;
	}
}//进程创建函数结束
int main()
{ 
 //系统初始化
	int num,i,j;
	run=ready.head=ready.tail=blocking;
	pfree=0;
	for(j=0;j<n-1;j++)
	pcbarea[j].next=j+1;
	pcbarea[n-1].next=-1;
	printf("输入进程编号(避免编号的冲突，以负数输入结束最多可以创建 10 个进程):\n");
	scanf("%d",&num);
	while(num>=0)
	{ 
		create(num);
		scanf("%d",&num);
	}
	sheduling(); //进程调度
	if(run!=-1)
	{ 
		printf ("进程标志符 进程状态 寄存器内容:ax bx cx dx pc psw:\n"); 
		printf("%8d%10d            %3d%3d%3d%3d%3d%3d\n",
			pcbarea[run].name, pcbarea[run].status,
			pcbarea[run].ax, pcbarea[run].bx,
			pcbarea[run].cx, pcbarea[run].dx, 
			pcbarea[run].pc, pcbarea[run].psw);
	}
	return 0;
}//main()结束
