#include <iostream>
#include <string>

using namespace std;

void print()
{
     system( "CLS" );
     system( "title C++ �ػ�����" );//����cmd���ڱ���
     system( "mode con cols=52 lines=18" );//���ڿ�ȸ߶�
     system( "color a9" );
     cout << " �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n"
          << " �U               C++ �ػ�����                   �U\n"
          << " �U  �����룺                                    �U\n"
          << " �U    1.ʵ�ֶ�ʱ�رռ����                      �U\n"
          << " �U    2.�����رռ����                          �U\n"
          << " �U    3.ע�������                              �U\n"
          << " �U    4.�������������                          �U\n"
          << " �U    5.ȡ���ػ���ע������(�������½���ʾ)      �U\n"
          << " �U    0.�˳�ϵͳ(��Ȼֱ�ӹر���һ����)          �U\n"
		  << " �U                                              �U\n"
          << " �U    ��������:wangminli                     �� �U\n"
          << " �U    ������΢��:http://weibo.com/wangminli  �� �U\n"
          << " �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";
     cout << "��������Ӧ�����ֲ��س��� "; 
}
int main()
{
    string c;
    char cmds[ 25 ] = "shutdown -s -t 000000000";
    print();
    cin >> c;
    while( c != "0" )
    {
           while( c == "1" )
           {
                  int num;
                  cout << "Please enter the time: " << endl;
                  cin >> num;
                  for( int i = 0; i < 9; i++ )
                  {
                       cmds[ 23 - i ] = static_cast< char >( num % 10 + 48 );
                       num = num / 10;
                  }
                  system( cmds );
                  break;
           }
           while( c == "2" )
           {
                  system( "shutdown -p" );
                  break;
           }
           while( c == "3" )
           {
                  system( "shutdown -l" );
                  break;
           }
           while( c == "4" )
           {
                  system( "shutdown -r -t 0" );
                  break;
           }
           while( c == "5" )
           {
                  system( "shutdown -a" );
                  break;
           }
           print();
           cin >> c;
    }
    return 0;
}