#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int ans[100001];
int dp[100001];
#define ls(p) (p*2)
#define rs(p) (p*2+1)
struct AB
{
	int l,r,maxn;
}tree[400001];
void Build(int p,int l,int r)
{
	tree[p]={l,r,0};
	if(l==r)
	{
		tree[p].maxn=0;
		return;
	}
	int mid=(l+r)/2;
	Build(ls(p),l,mid),Build(rs(p),mid+1,r);
}
int Query(int p,int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	if(l<=tree[p].l&&tree[p].r<=r)
	{
		return tree[p].maxn;
	}
	int res=0;
	int mid=(tree[p].l+tree[p].r)/2;
	if(l<=mid)
	{
		res=max(res,Query(ls(p),l,r));
	}
	if(r>mid)
	{
		res=max(res,Query(rs(p),l,r));
	}
	return res;
}
void Update(int p,int pos,int v)
{
	if(pos==tree[p].l&&tree[p].r==pos)
	{
		tree[p].maxn=v;
		return;
	}
	int mid=(tree[p].l+tree[p].r)/2;
	if(pos<=mid)
	{
		Update(ls(p),pos,v);
	}
	else
	{
		Update(rs(p),pos,v);
	}
	tree[p].maxn=max(tree[ls(p)].maxn,tree[rs(p)].maxn);
}
int main(){
	freopen("tp.in","r",stdin);
	freopen("tp.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	Build(1,1,n);
	for(int i=n;i>=1;i--)
	{
		dp[a[i]]=Query(1,1,a[i]-1)+1;
		Update(1,a[i],dp[a[i]]);
		ans[i]=dp[a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}