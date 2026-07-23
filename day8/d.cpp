#include<bits/stdc++.h>
using namespace std;
bool flag=0;
int T;
int n,m,a[6],vis[11];
vector<int>v[6];
bool check()
{
	for(int i=1;i<=m;i++)
	{
		if(vis[i]>1)
		{
			return false;
		}
	}
	return true;
}
void dfs(int idx)
{
	if(idx==n+1)
	{
		if(check())
		{
			flag=1;
		}
		return;
	}
	for(int i=1;i<1<<m;i++)
	{
		int p[11],pos=0;
		int k=1;
		for(int j=0;j<m;j++)
		{
			if(i>>j&1)
			{
				k=k*(j+1);
				vis[j+1]++;
				p[++pos]=j+1;
			}
		}
		if(k==a[idx])
		{
			dfs(idx+1);
		}
		for(int j=1;j<=pos;j++)
		{
			vis[p[j]]--;
		}
	}
}
int main(){
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		cin>>n>>m;
		flag=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		memset(vis,0,sizeof vis);
		dfs(1);
		if(flag==1)
		{
			cout<<"No\n";
		}
		else
		{
			cout<<"Yes\n";
		}
	}
	return 0;
}