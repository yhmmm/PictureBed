#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int posx=0,posy=0;
long long ans=0;
void solve(int px,int py,int x,int y)
{
	int da=(py-px+n)%n;
	if(x-da>=0)
	{
		x-=da;
		if(posx!=posy)
		{
			ans++;
		}
		ans=ans+(long long)x/n;
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>n>>m;
	for(int _=1;_<=m;_++)
	{
		cin>>x>>y;
		solve(posx,posy,x,y);
		posx=(posx+x)%n;
		solve(posy,posx,y,x);
		posy=(posy+y)%n;
	}
	cout<<ans;
	return 0;
}