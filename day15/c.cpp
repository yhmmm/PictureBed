#include<bits/stdc++.h>
using namespace std;
int n,m;
int pos=0,head[5001];
int _u,_v,_w;
int f[5001];
struct edge
{
	int u,v,w,nxt;
	bool operator<(const edge &_x)const
	{
		return w>_x.w;
	}
}e[400001];
void addedge(int u,int v,int w)
{
	e[++pos]={u,v,w,head[u]};
	head[u]=pos;
}
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	sort(e+1,e+m+1);
}
int find(int u)
{
	if(f[u]==u)
	{
		return u;
	}
	f[u]=find(f[u]);
	return f[u];
}
void merge(int u,int v)
{
	f[find(u)]=find(v);
}
bool judge(int u,int v)
{
	return find(u)==find(v);
}
int main(){
	cin>>n;
		m=n*(n-1);
		memset(head,0,sizeof head);
		pos=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				addedge(i,j,__gcd(i,j));
			}
		}
		init(n);
		int cnt=0,ans=0;
		for(int i=1;i<=m;i++)
		{
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(!judge(u,v))
			{
				ans+=w;
				merge(u,v);
				cout<<u<<' '<<v<<' '<<e[i].w<<endl;
			}
		}
		cout<<ans<<',';
	
	return 0;
}