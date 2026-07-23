#include<bits/stdc++.h>
using namespace std;
int T;
long long n,m,fold,cnt,xa,ya,xb,yb;
int main(){
	freopen("paper.in","r",stdin);
	freopen("paper.out","w",stdout);
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		cin>>m>>n;
		cin>>fold>>cnt;
		cin>>ya>>xa>>yb>>xb;
		long long ans=0;
		ans=(cnt+1)*(xb-xa)*(yb-ya);
		long long a=fold,b=m-fold;
		long long len=min(a,b),lenc;
		if(len<=ya)
		{
			lenc=0;
		}
		else if(ya<len&&len<=yb)
		{
			lenc=len-ya;
		}
		else
		{
			lenc=yb-ya;
		}
		ans=ans+(cnt+1)*(xb-xa)*(lenc);
		cout<<n*m-ans<<endl;
	}
	return 0;
}