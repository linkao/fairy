//�ļ�����number_guess.cpp
//�ֿ� 
 
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

int main()
{
	int num1,num2,num3,gnum1,gnum2,gnum3,i,win=0,loss=0,a=0,b=0;      //num1��num2��num3���������ɵ��������gnum1��2��3���²������win��loss��ͳ����Ӯ 
	char jud = 'Y',jud2 = 'l';                                        //a��b��������ʾ ��jud���Ƿ������Ϸ��jud2��ȷ����Ϸʤ���� 
	
	while (jud=='Y' || jud == 'y') {
	
	srand(time(NULL));		                                          //��������ӳ�ʼ���� 
	
	num1 = rand()%9 + 1;                                              //�������һ����1��9֮������� �� 
	num2 = rand()%9 + 1;
	  while (num2 == num1)  num2 = rand()%9 +1;						 
	num3 = rand()%9 + 1;
	  while (num3 == num2 || num3 == num1)  num3 = rand()%9 + 1;      //ȷ���������������ͬ������
		
		for (i=0;i<7;++i) {												//�ߴλ��᣻ 
			cout<<"������3����²�����֣�"<<endl;
			cin>>gnum1>>gnum2>>gnum3;
			if (gnum1==num1 & gnum2==num2 & gnum3==num3) {				//�¶ԣ�����ѭ�� ����ֵ�����Ӯ�˵���Ϣ 
				jud2 = 'w';break;}
			else{
				if (gnum1 == num1) a += 1;								// û�в¶ԣ� 
				if (gnum1 == num2 || gnum1 == num3) b +=1;				// 
				if (gnum2 == num2) a += 1;								// 
				if (gnum2 == num1 || gnum2 == num3) b +=1;				//ͳ��ABǰ����ֵ �� 
				if (gnum3 == num3) a += 1;								// 
				if (gnum3 == num1 || gnum3 == num2) b +=1;				// 
				cout<<a<<"A"<<b<<"B"<<endl; 
				a = 0;b = 0;
			}
		}
		if (jud2 == 'w') {cout<<"��ϲ����Ӯ��"<<endl;win += 1;}
		else {cout<<"���ź�����û���ڹ涨�����ڲ¶ԡ����� "<<num1<<' '<<num2<<' '<<num3<<endl;loss += 1;}
		jud2 = 'l';
		
		cout<<"�Ƿ������Ϸ��Y/N��?  ";
		cin>>jud;
		if (jud == 'N' || jud == 'n') { 
		cout<<"��һ������"<<win+loss<<"�֣�"<<"Ӯ��"<<win<<"�֣�"<<"����"<<loss<<"�֡�"; 
		} 
	}
	return 0;
}
