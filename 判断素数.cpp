#include<iostream>
#include<cmath>
using namespace std;
int main()
{
bool prime;
	for(int i=1;i<=20;i++)
        {
	for(int j=1;j<=20;j++)
{
		int k=i+j;
		int t=sqrt(k)
		for(int p=2;p<=t;p++)
		if(k%t==0)
              {
		prime=flase;
		break;
               }
		if(prime)
{
		cout<<"����Ϊ"<<k<<"������������"<<i<<"  "<<j<<endl;
}
	
}
	}
}






	k=int(sqrt(m));
		for(i=2;i<=k;i++)    //�ж�m%2������m����
			if(m%k==0)
			{
				prime=false;
				break;
			}