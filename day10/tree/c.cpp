#include<bits/stdc++.h>
using namespace std;
int n,_u,_v;
int fa[100001];
int dep[100001];
bool vis[100001];
int ans[100001];
vector<int>tree[100001];
struct node
{
	int maxdep,smaxdep;
	int idxmaxdep,idxsmaxdep;
}t[100001];
struct cmp
{
	int d,idx;
	bool operator<(const cmp &_x)const
	{
		if(d!=_x.d)
		{
			return d>_x.d;
		}
		return idx<_x.idx;
	}
};
void init(int u,int f)
{
	vis[u]=1;
	fa[u]=f;
	dep[u]=dep[f]+1;
	if(tree[u].size()==1)
	{
		t[u].maxdep=dep[u];
		t[u].idxmaxdep=u;
	}
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		if(vis[v])
		{
			continue;
		}
		init(v,u);
		cmp a[6];
		int pos=0;
		a[++pos]={t[u].maxdep,t[u].idxmaxdep};
		a[++pos]={t[u].smaxdep,t[u].idxsmaxdep};
		a[++pos]={t[v].maxdep,v};
		sort(a+1,a+pos+1);
		t[u].maxdep=a[1].d;
		t[u].idxmaxdep=a[1].idx;
		t[u].smaxdep=a[2].d;
		t[u].idxsmaxdep=a[2].idx;
	}
}
void dfs(int u)
{
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		if(v==fa[u])
		{
			continue;
		}
		t[v].maxdep--;
		t[v].smaxdep--;
		int newdep;
		if(v==t[u].idxmaxdep)
		{
			newdep=t[u].smaxdep+1;
		}
		else
		{
			newdep=t[u].maxdep+1;
		}
		
		if(newdep>=t[v].maxdep)
		{
			t[v].smaxdep=t[v].maxdep;
			t[v].idxsmaxdep=t[v].idxmaxdep;
			t[v].maxdep=newdep;
			t[v].idxmaxdep=u;
		}
		else if(newdep>t[v].smaxdep)
		{
			t[v].smaxdep=newdep;
			t[v].idxsmaxdep=u;
		}
		ans[v]=max(ans[v],t[v].maxdep);
		dfs(v);
		t[v].maxdep++;
		t[v].smaxdep++;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int _=1;_<n;_++)
	{
		t[_].maxdep=t[_].smaxdep=-1;
		t[_].idxmaxdep=t[_].idxsmaxdep=-1;
		cin>>_u>>_v;
		tree[_u].push_back(_v);
		tree[_v].push_back(_u);
	}
	dep[0]=-1;
	init(1,0);
	ans[1]=t[1].maxdep;
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}	
	return 0;
}