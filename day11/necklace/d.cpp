#include<bits/stdc++.h>
using namespace std;
int n,a[501],b[501],aa[501];
int cnt[501]={0};
int solve(int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	if(l==r)
	{
		if(a[l]==b[l])
		{
			return 0;
		}
		a[l]=b[l];
		return 1;
	}
	int res=0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]==b[i])
		{
			continue;
		}
		int bg=i,ed=i;
		cnt[b[i]]++;
		while(ed+1<=r&&a[ed+1]!=b[ed+1])
		{
			ed++;
			cnt[b[ed]]++;
		}
		int maxcnt=0,num;
		int s,t;
		for(int j=bg;j<=ed;j++)
		{
			if(cnt[b[j]]>maxcnt)
			{
				s=j;
				maxcnt=cnt[b[j]];
				num=b[j];
				cnt[b[j]]=0;
			}
		}
		for(int j=ed;j>=bg;j--)
		{
			if(b[j]==num)
			{
				t=j;
				break;
			}
		}
		for(int j=s;j<=t;j++)
		{
			a[j]=num;
		}
		res++;
		i=ed+1;
		res+=solve(bg,ed);
	}
	return res;
}
int main(){
	freopen("necklace.in","r",stdin);
	freopen("necklace.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		aa[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	int ans=solve(1,n);
	reverse(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=aa[i];
	}
	ans=min(ans,solve(1,n));
	cout<<ans;
	return 0;
}