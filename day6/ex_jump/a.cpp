#include<bits/stdc++.h>
using namespace std;
long long T,n,s,t;
long long QuickPow(long long a,long long b)
{
	long long res=1;
	while(b>0)
	{
		if(b&1)
		{
			res=res*a;
		}
		a=a*a;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		cin>>n>>s>>t;
		long long k=QuickPow(2,n)-1;
		if(s!=t)
		{
			cout<<(k^s)+(k^t)<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}