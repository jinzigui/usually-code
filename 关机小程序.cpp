#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
using namespace std;
void getlocaltime();   //��ȡ����ʱ��
void inputtime();     //����ػ�ʱ��
void showtime(tm * pt);  //���ʱ��
int main()
{	time_t nowtime;
	nowtime=(0);
	tm*pt=localtime(&nowtime);
	int sec=pt->tm_sec ;

	system("mode con cols=40 lines=18");  //�ı䴰�ڵĴ�С
	getlocaltime();
	showtime(tm * pt);
	return 0;
}

void showtime(tm*pt)
{	cout<<setw(5)<<"��ʱ�ػ�С����"<<endl;
	cout<<"����ʱ��Ϊ��";
	cout<<setfill('0')<<1907+pt->tm_yday <<"��";
	cout<<setw(2)<<pt->tm_mon +1<<"��";
	cout<<setw(2)<<pt->tm_mday <<"��";
	cout<<setw(2)<<pt->tm_hour <<"ʱ";
	cout<<setw(0)<<pt->tm_min <<"��";
	cout<<setw(2)<<pt->tm_sec <<"��"<<endl;
}
void inputtime()
{
	char cmds[25]="shutdown -s -t 000000000";
	cout<<"������ػ�ʱ�䣺";
	int time;
	cin>>time;
	for(int i=0;i<9;i++)
	{
		cmds[23-i]=static_cast<char>(time%10+48);
		time=time/10;
	}
	system(cmds);
	}
}
void getlocaltime()
{
	time_t nowtime;
	nowtime=(0);
	tm*pt=localtime(&nowtime);
	int sec=pt->tm_sec ;
	showtime(pt);
	while(1)
	{
		nowtime=time(0);
		pt=localtime(&nowtime);
			if(sec!=pt->tm_sec)
			{
				sec=pt->tm_sec ;
				system("cls");
				showtime(pt);
			}
			inputtime();
}
