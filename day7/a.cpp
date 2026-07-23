#include<bits/stdc++.h>
using namespace std;
int id=1;
int n,_n,a[500001],b[500001],ls[2000001],rs[2000001];
map<int,int>mp;
struct node
{
	int cnt=0;
}tree[2000001];
void init()
{
	for(int i=1;i<=_n*4;i++)
	{
		ls[i]=rs[i]=-1;
	}
	sort(a+1,a+_n+1);
	n=unique(a+1,a+_n+1)-a-1;
	for(int i=1;i<=n;i++)
	{
		mp[a[i]]=i;
	}
}
void pushup(int p)
{
	tree[p].cnt=tree[ls[p]].cnt+tree[rs[p]].cnt;
}
int update(int p,int l,int r,int val,int op)
{
	if(p==-1)
	{
		p=++id;
	}
	if(l==r)
	{
		tree[p].cnt+=op;
		return p;
	}
	int mid=(l+r)/2;
	if(val<=mid)
	{
		ls[p]=update(ls[p],l,mid,val,op);
	}
	else
	{
		rs[p]=update(ls[p],mid+1,r,val,op);
	}
	pushup(p);
	return p;
}
void query()
{

}
int main(){
	cin>>_n;
	for(int i=1;i<=_n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	init();
	long long ans=0;
	for(int i=1;i<=_n;i++)
	{
		int val=mp[b[i]];
		update(1,1,n,val,1);
		
	}
	cout<<ans<<endl;
	return 0;
}