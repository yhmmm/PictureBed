#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int dir=4;
int posx=0,posy=0;
bool check(int x,int y)
{
	if(x==0&&y==0)
	{
		return true;
	}
	if(x==0&&y==m)
	{
		return true;
	}
	if(x==n&&y==0)
	{
		return true;
	}
	if(x==n&&y==m)
	{
		return true;
	}
	return false;
}
int main(){
	freopen("reflect.in","r",stdin);
	freopen("reflect.out","w",stdout);
	cin>>n>>m;
	while(!check(posx,posy)||ans==0)
	{
		ans++;
		if(dir==4)
		{
			int dx=n-posx;
			int dy=m-posy;
			int dis=min(dx,dy);
			posx+=dis;
			posy+=dis;
			if(dis==dx)
			{
				dir=1;
			}
			else
			{
				dir=3;
			}
		}
		else if(dir==2)
		{
			int dx=posx;
			int dy=posy;
			int dis=min(dx,dy);
			posx-=dis;
			posy-=dis;
			if(dis==dx)
			{
				dir=3;
			}
			else
			{
				dir=1;
			}
		}
		else if(dir==1)
		{
			int dx=posx;
			int dy=m-posy;
			int dis=min(dx,dy);
			posx-=dis;
			posy+=dis;
			if(dis==dx)
			{
				dir=4;
			}
			else
			{
				dir=2;
			}
		}
		else if(dir==3)
		{
			int dx=n-posx;
			int dy=posy;
			int dis=min(dx,dy);
			posx+=dis;
			posy-=dis;
			if(dis==dx)
			{
				dir=2;
			}
			else
			{
				dir=4;
			}
		}
		//cout<<posx<<' '<<posy<<' '<<dir<<endl;
		if(ans>100000000)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<ans-1<<endl;
	return 0;
}