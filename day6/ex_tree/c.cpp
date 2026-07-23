#include<bits/stdc++.h>
using namespace std;
struct son
{
	int u,dep;
	bool operator<(const son &_x)const
	{
		return dep<_x.dep;
	}
}s[200001];
int T,n,f[200001],pos=0;
vector<int>tree[200001];
map<pair<int,int>,int>mp;
void dfs(int u,int dep)
{
	if((int)tree[u].size()==0)
	{
		s[++pos]={u,dep};
	}
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		if(v==f[u])
		{
			continue;
		}
		dfs(v,dep+1);
	}
}
pair<int,int>makepair(int x,int y)
{
	return make_pair(min(x,y),max(x,y));
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		cin>>n;
		mp.clear();
		f[1]=-1;
		for(int i=2;i<=n;i++)
		{
			cin>>f[i];
			tree[f[i]].push_back(i);
		}
		pos=0;
		dfs(1,1);
		sort(s+1,s+pos+1);
		int ans=0;
		for(int i=1;i<=pos;i++)
		{
			int cnt=0;
			int u=s[i].u;
			while(f[u]!=-1&&mp[makepair(u,f[u])]==0)
			{
				mp[makepair(u,f[u])]=1;
				u=f[u];
				cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			tree[i].clear();
		}
	}
	return 0;
}