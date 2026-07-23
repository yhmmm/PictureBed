#include<bits/stdc++.h>
using namespace std;
int n;
int f[10000001];
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
}
int find(int u)
{
	if(f[u]==u)
	{
		return u;
	}
	f[u]=find(f[u]);
	return f[u];
}
void merge(int u,int v)
{
	f[find(u)]=find(v);
}
bool judge(int u,int v)
{
	return find(u)==find(v);
}
int main(){
	cin>>n;
	init(n);
	int cnt=0;
	long long ans=0;
	for(int w=2;w<=n/2;w++)
	{
		for(int k=2*w;k<=n;k+=w)
		{
			if(!judge(w,k))
			{
				cnt++;
				ans+=w;
				merge(w,k);
			}
			if(cnt==n-1)
			{
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}