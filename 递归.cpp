#include <IOSTREAM>
using namespace std;
bool visited[10];
void dfs(int pos,int cnt,int n,int k,int a[])
{
	if (cnt==k)
	{
		for(int i=0;i<n;i++)
			if(visited[i])
				cout<<a[i]<<" ";
			cout<<endl;
			return;
	}
	if(pos==n)return;
	if(!visited[pos])
	{
		visited[pos]=true;
		dfs(pos+1,cnt+1,n,k,a);
		visited[pos]=false;
	}
	dfs(pos+1,cnt,n,k,a);
}
int main()
{
	int i,n,k,a[10];
	while(cin>>n>>k)
	{
		for(i=0;i<n;i++)
			a[i]=i+1;
		dfs(0,0,n,k,a);
	}
	return 0;
}
