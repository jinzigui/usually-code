#include<windows.h>
#include<iostream>
const int MAX_BUFFER_LEN =500;
using namespace std;
int main()
{
	cout<<"�õ�����������û���"<<endl;
	char szBuffer[MAX_BUFFER_LEN];
	DWORD dwNameLen;   //�����޷��ų����α����ַ
	dwNameLen=MAX_BUFFER_LEN;
	if(!GetComputerName(szBuffer,&dwNameLen))  //�ж��Ƿ��ȡ�ɹ�
		cout<<"Error"<<GetLastError()<<endl;
	else
		cout<<"�������Ϊ��"<<szBuffer<<endl;
	dwNameLen=MAX_BUFFER_LEN;
	if(!GetUserName(szBuffer,&dwNameLen))
		cout<<"Error"<<GetLastError();
	else
		cout<<"��ǰ�û���Ϊ"<<szBuffer<<endl;


	cout<<"Ҫ�޸ļ���������û�����Y/N"<<endl;
	char a;
	cin>>a;
	if(a=='Y'||a=='y')
	{
		cout<<"�������µļ��������";
		cin>>szBuffer;
		if(strlen(szBuffer)!=0)
		{
			if(SetComputerName(szBuffer))   //�޸ļ�������
			{
				cout<<"�޸ļ�������ɹ���"<<endl;
			}
			else
			cout<<"��Ǹ���޸Ĳ��ɹ���"<<endl;
		}
			cout<<"�������µ��û�����";
			cin>>szBuffer;
			if(strlen(szBuffer)!=0)
			{
				if(SetUserName(szBuffer))
				{
					cout<<"�޸��û����ɹ���������Ч���Ƿ�����������Y/N"<<endl;
			char b;
			cin>>b;
			if('y'==b||'Y'==b)
			{
				system("shutdown -r -t 0");
			}
			else
			cout<<"��ʱ��������ף��������죡"<<endl;
				}
			else
			cout<<"��Ǹ���޸Ĳ��ɹ���"<<endl;
			}
	}
	return 0;
}