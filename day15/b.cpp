#include<bits/stdc++.h>
using namespace std;
int n,m;
int _u,_v,_w;
int pos=0,head[50001];
int dis[50001][7];
int vis[50001];
struct T
{
	int t,idx;
	bool operator<(const T &_x)const
	{
		return idx<_x.idx;
	}
}tsk[6];
struct edge
{
	int u,v,w,nxt;
}e[200001];
struct node
{
	int u;
	int dis;
	bool operator<(const node &_x)const
	{
		return dis>_x.dis;
	}
};
void addedge(int u,int v,int w)
{
	e[++pos]={u,v,w,head[u]};
	head[u]=pos;
}
int ReadInt()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	}
	return x*f;
}
void Dijkstra(int s,int k)
{
	for(int i=1;i<=n;i++)
	{
		dis[i][k]=0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	dis[s][k]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(q.size())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[u][k]+w<dis[v][k])
			{
				dis[v][k]=dis[u][k]+w;
				q.push({v,dis[v][k]});
			}
		}
	}
}
int solve()
{
	long long cur=0;
	for(int i=1;i<=5;i++)
	{
		int from=tsk[i-1].idx,to=tsk[i].t;
		cur+=dis[to][from];
	}
	return cur;
}
int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	n=ReadInt(),m=ReadInt();
	tsk[0].t=1;
	tsk[1].t=ReadInt(),tsk[2].t=ReadInt(),tsk[3].t=ReadInt(),tsk[4].t=ReadInt(),tsk[5].t=ReadInt();
	for(int i=1;i<=m;i++)
	{
		_u=ReadInt(),_v=ReadInt(),_w=ReadInt();
		addedge(_u,_v,_w);
		addedge(_v,_u,_w);
	}
	for(int i=0;i<=5;i++)
	{
		tsk[i].idx=i;
		Dijkstra(tsk[i].t,i);
	}
	int ans=0x3f3f3f3f;
	do
	{
		ans=min(ans,solve());
	}while(next_permutation(tsk+1,tsk+5+1));
	printf("%d",ans);
	return 0;
}