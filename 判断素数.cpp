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
		cout<<"素数为"<<k<<"满足条件的有"<<i<<"  "<<j<<endl;
}
	
}
	}
}






	k=int(sqrt(m));
		for(i=2;i<=k;i++)    //判断m%2到根号m即可
			if(m%k==0)
			{
				prime=false;
				break;
			}