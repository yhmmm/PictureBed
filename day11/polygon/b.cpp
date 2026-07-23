#include<bits/stdc++.h>
using namespace std;
int T,n;
long long sum,maxa,a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		cin>>n;
		sum=0;
		maxa=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			sum+=a;
			maxa=max(maxa,a);	
		}
		if(sum>2*maxa)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}