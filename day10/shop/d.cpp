#include<bits/stdc++.h>
using namespace std;
int n,m;
int _u,_v;
int fa[100001];
int de[100001];
int vis[21];
vector<int>tree[100001];
vector<int>v;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			return true;
		}
	}
	return false;
}
int solve()
{
	int t=0;
	while(check())
	{
		t++;
		bool flag=0;
		for(int i=0;i<v.size();i++)
		{
			if(fa[v[i]]!=-1)
			{
				flag=1;
				v[i]=fa[v[i]];
				vis[v[i]]=0;
			}
		}
		if(flag==0)
		{
			return INT_MAX;
		}
	}
	return t;
}
void subtaskone()
{
	int mintime=INT_MAX;
	for(int i=1;i<1<<n;i++)
	{
		int cnt=0;
		v.clear();
		for(int j=1;j<=n;j++)
		{
			vis[j]=de[j];
		}
		for(int j=0;j<n;j++)
		{
			if(i>>j&1)
			{
				cnt++;
				v.push_back(j+1);
				vis[j+1]=0;
			}
		}
		if(cnt==m)
		{
			mintime=min(mintime,solve());
		}
	}
	if(mintime==INT_MAX)
	{
		cout<<-1;
	}
	else
	{
		cout<<mintime;
	}
}
void init(int u,int f)
{
	fa[u]=f;
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		if(v==f)
		{
			continue;
		}
		init(v,u);
	}
}
int main(){
	// freopen("shop.in","r",stdin);
	// freopen("shop.out","w",stdout);
	cin>>n>>m;
	for(int _=1;_<n;_++)
	{
		cin>>_u>>_v;
		tree[_u].push_back(_v);
		tree[_v].push_back(_u);
	}
	int decnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>de[i];
		decnt+=de[i];
	}
	init(1,-1);
	if(n<=20)
	{
		subtaskone();
		return 0;
	}
	if(m>=decnt)
	{
		cout<<0;
		return 0;
	}
	
	return 0;
}