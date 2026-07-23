#include<bits/stdc++.h>
using namespace std;
int n,m,mrk[2001][2001];
char s[2001][2001];
struct node
{
	int x,y;
};
int dir[2][2]={{1,0},{0,1}};
int main(){
	freopen("slate.in","r",stdin);
	freopen("slate.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mrk[i][j]=0;
			scanf(" %c",&s[i][j]);
		}
	}
	mrk[0][1]=1;
	for(int step=2;step<=n+m;step++)
	{
		char choose='z';
		for(int y=1;y<=m;y++)
		{
			int x=step-y;
			if(x<1||x>n)
			{
				continue;
			}
			if(mrk[x-1][y]==0&&mrk[x][y-1]==0)
			{
				continue;
			}
			choose=min(choose,s[x][y]);
		}
		for(int y=1;y<=m;y++)
		{
			int x=step-y;
			if(x<1||x>n)
			{
				continue;
			}
			if(mrk[x-1][y]==0&&mrk[x][y-1]==0)
			{
				continue;
			}
			if(s[x][y]==choose)
			{
				mrk[x][y]=1;
			}
		}
		printf("%c",choose);
	}
	return 0;
}