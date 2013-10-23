#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
using namespace std;
void getlocaltime();   //获取当地时间
void inputtime();     //输入关机时间
void showtime(tm * pt);  //输出时间
int main()
{	time_t nowtime;
	nowtime=(0);
	tm*pt=localtime(&nowtime);
	int sec=pt->tm_sec ;

	system("mode con cols=40 lines=18");  //改变窗口的大小
	getlocaltime();
	showtime(tm * pt);
	return 0;
}

void showtime(tm*pt)
{	cout<<setw(5)<<"定时关机小程序"<<endl;
	cout<<"现在时间为：";
	cout<<setfill('0')<<1907+pt->tm_yday <<"年";
	cout<<setw(2)<<pt->tm_mon +1<<"月";
	cout<<setw(2)<<pt->tm_mday <<"日";
	cout<<setw(2)<<pt->tm_hour <<"时";
	cout<<setw(0)<<pt->tm_min <<"分";
	cout<<setw(2)<<pt->tm_sec <<"秒"<<endl;
}
void inputtime()
{
	char cmds[25]="shutdown -s -t 000000000";
	cout<<"请输入关机时间：";
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
