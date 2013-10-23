#include<windows.h>
#include<iostream>
const int MAX_BUFFER_LEN =500;
using namespace std;
int main()
{
	cout<<"得到计算机名和用户名"<<endl;
	char szBuffer[MAX_BUFFER_LEN];
	DWORD dwNameLen;   //定义无符号长整形保存地址
	dwNameLen=MAX_BUFFER_LEN;
	if(!GetComputerName(szBuffer,&dwNameLen))  //判断是否获取成功
		cout<<"Error"<<GetLastError()<<endl;
	else
		cout<<"计算机名为："<<szBuffer<<endl;
	dwNameLen=MAX_BUFFER_LEN;
	if(!GetUserName(szBuffer,&dwNameLen))
		cout<<"Error"<<GetLastError();
	else
		cout<<"当前用户名为"<<szBuffer<<endl;


	cout<<"要修改计算机名和用户名吗？Y/N"<<endl;
	char a;
	cin>>a;
	if(a=='Y'||a=='y')
	{
		cout<<"请输入新的计算机名：";
		cin>>szBuffer;
		if(strlen(szBuffer)!=0)
		{
			if(SetComputerName(szBuffer))   //修改计数机名
			{
				cout<<"修改计算机名成功！"<<endl;
			}
			else
			cout<<"抱歉！修改不成功！"<<endl;
		}
			cout<<"请输入新的用户名：";
			cin>>szBuffer;
			if(strlen(szBuffer)!=0)
			{
				if(SetUserName(szBuffer))
				{
					cout<<"修改用户名成功！重启生效，是否现在重启？Y/N"<<endl;
			char b;
			cin>>b;
			if('y'==b||'Y'==b)
			{
				system("shutdown -r -t 0");
			}
			else
			cout<<"暂时不重启，祝你生活愉快！"<<endl;
				}
			else
			cout<<"抱歉！修改不成功！"<<endl;
			}
	}
	return 0;
}