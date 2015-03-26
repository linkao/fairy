//文件名：number_guess.cpp
//林考 
 
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

int main()
{
	int num1,num2,num3,gnum1,gnum2,gnum3,i,win=0,loss=0,a=0,b=0;      //num1、num2、num3：电脑生成的随机数；gnum1、2、3：猜测的数；win、loss：统计输赢 
	char jud = 'Y',jud2 = 'l';                                        //a、b：数字提示 ；jud：是否继续游戏；jud2：确认游戏胜负； 
	
	while (jud=='Y' || jud == 'y') {
	
	srand(time(NULL));		                                          //随机数种子初始化； 
	
	num1 = rand()%9 + 1;                                              //随机生成一个在1到9之间的整数 ； 
	num2 = rand()%9 + 1;
	  while (num2 == num1)  num2 = rand()%9 +1;						 
	num3 = rand()%9 + 1;
	  while (num3 == num2 || num3 == num1)  num3 = rand()%9 + 1;      //确保随机生成三个不同的数；
		
		for (i=0;i<7;++i) {												//七次机会； 
			cout<<"请输入3个你猜测的数字："<<endl;
			cin>>gnum1>>gnum2>>gnum3;
			if (gnum1==num1 & gnum2==num2 & gnum3==num3) {				//猜对，跳出循环 ；赋值以输出赢了的信息 
				jud2 = 'w';break;}
			else{
				if (gnum1 == num1) a += 1;								// 没有猜对； 
				if (gnum1 == num2 || gnum1 == num3) b +=1;				// 
				if (gnum2 == num2) a += 1;								// 
				if (gnum2 == num1 || gnum2 == num3) b +=1;				//统计AB前的数值 ； 
				if (gnum3 == num3) a += 1;								// 
				if (gnum3 == num1 || gnum3 == num2) b +=1;				// 
				cout<<a<<"A"<<b<<"B"<<endl; 
				a = 0;b = 0;
			}
		}
		if (jud2 == 'w') {cout<<"恭喜，你赢了"<<endl;win += 1;}
		else {cout<<"很遗憾，你没有在规定次数内猜对。答案是 "<<num1<<' '<<num2<<' '<<num3<<endl;loss += 1;}
		jud2 = 'l';
		
		cout<<"是否继续游戏（Y/N）?  ";
		cin>>jud;
		if (jud == 'N' || jud == 'n') { 
		cout<<"你一共玩了"<<win+loss<<"局，"<<"赢了"<<win<<"局，"<<"输了"<<loss<<"局。"; 
		} 
	}
	return 0;
}
