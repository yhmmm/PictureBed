#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long h[1000001];
bool check(long long mid)
{
	long long k=0;
	for(int i=1;i<=n;i++)
	{
		if(h[i]>mid)
		{
			k=k+(h[i]-mid);
		}
	}
	return k>=m;
}
int main(){
	freopen("cuttree.in","r",stdin);
	freopen("cuttree.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	long long ans=0;
	long long l=0,r=2000000000;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}