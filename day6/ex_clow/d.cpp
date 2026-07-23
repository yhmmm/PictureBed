#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long n,a[100001],vis[100001];
long long tota=0,tot=0;
long long fac[100001];
void init()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	fac[0]=1;
	for(long long i=1;i<=n;i++)
	{
		fac[i]=(fac[i-1]*i)%mod;
	}
}
long long QuickPow(long long a,long long b,long long p)
{
	long long res=1;
	while(b>0)
	{
		if(b&1)
		{
			res=(res*a)%p;
		}
		a=(a*a)%p;
		b>>=1;
	}
	return res;
}
long long C(long long n,long long m)
{
	return fac[n]*(QuickPow(fac[m],mod-2,mod)*QuickPow(fac[n-m],mod-2,mod)%mod)%mod;
}
int main(){
	freopen("clow.in","r",stdin);
	freopen("clow.out","w",stdout);
	scanf("%lld",&n);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=-1)
		{
			vis[a[i]]=1;
		}
		else
		{
			tot++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1&&vis[i]==0)
		{
			tota++;
		}
	}
	long long ans=0;
	for(long long i=0;i<=tota;i++)
	{
		long long k=(C(tota,i)*fac[tot-i])%mod;
		if(i%2==0)
		{
			ans+=k;
		}
		else
		{
			ans-=k;
		}
	}
	printf("%lld",((ans%mod)+mod)%mod);
	return 0;
}