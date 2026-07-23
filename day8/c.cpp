#include<bits/stdc++.h>
using namespace std;
string s;
int ans=INT_MAX;
int n,mid;
int maxlenleft=0,maxlenright=0;
map<pair<int,int>,pair<int,int> >mpleft,mpright;
map<int,pair<int,int> >mp;
void dfsleft(int pos,int len,int totval,int opcnt,int nownum)
{
	if(pos==mid+1)
	{
		if(totval+nownum>n)
		{
			return;
		}
		if(mpleft[make_pair(totval+nownum,len)].second!=-1||mpleft[make_pair(totval+nownum,len)].first>opcnt)
		{
			mpleft[make_pair(totval+nownum,len)]=make_pair(opcnt,-1);
			mp[totval+nownum]=make_pair(opcnt,-1);
		}
		maxlenleft=max(maxlenleft,len);
		return;
	}
	if(pos>1)
	{
		int t=totval+nownum;
		dfsleft(pos+1,1,t,opcnt+1,s[pos-1]-'0');
	}
	if(nownum*10+(s[pos-1]-'0')<=n)
	{
		dfsleft(pos+1,len+1,totval,opcnt,nownum*10+(s[pos-1]-'0'));
	}
}
void dfsright(int pos,int len,int totval,int opcnt,int nownum,int isfirstlen)
{
	if(pos==(int)s.size()+1)
	{
		if(totval+nownum>n)
		{
			return;
		}
		if(mp[n-totval-nownum].second==-1)
		{
			ans=min(ans,mp[n-totval-nownum].first+opcnt+1);
		}
		if(mpright[make_pair(totval+nownum,len)].second!=-1||mpright[make_pair(totval+nownum,len)].first>opcnt)
		{
			mpright[make_pair(totval+nownum,len)]=make_pair(opcnt,-1);
		}
		maxlenright=max(maxlenright,len);
		return;
	}
	if(pos>mid+1)
	{
		int t=totval+nownum;
		dfsright(pos+1,len,t,opcnt+1,s[pos-1]-'0',0);
	}
	if(nownum*10+(s[pos-1]-'0')<=n)
	{
		int l=len+isfirstlen;
		dfsright(pos+1,l,totval,opcnt,nownum*10+(s[pos-1]-'0'),isfirstlen);
	}
}
int main(){
	cin>>s>>n;
	if(s.size()==1)
	{
		if(s[0]-'0'==n)
		{
			cout<<0;
		}
		else
		{
			cout<<-1;
		}
		return 0;
	}
	mid=((int)s.size()+1)/2;
	dfsleft(1,0,0,0,0);
	dfsright(mid+1,0,0,0,0,1);
	for(int lenleft=1;lenleft<=maxlenleft;lenleft++)
	{
		long long k=0;
		for(int i=mid-lenleft+1;i<=mid;i++)
		{
			k=k*10+(s[i-1]-'0');
		}
		long long l=k;
		long long p=0;
		for(int lenright=mid+1;lenright<=(int)s.size();lenright++)
		{
			p=p*10+(s[lenright-1]-'0');
			l=l*10+(s[lenright-1]-'0');
			for(int vleft=0;vleft<=n;vleft++)
			{
				long long vright=n-vleft-l;
				if(mpleft[make_pair(vleft+k,lenleft)].second==-1&&mpright[make_pair(vright+p,lenright-mid)].second==-1)
				{
					ans=min(ans,mpleft[make_pair(vleft+k,lenleft)].first+mpright[make_pair(vright+p,lenright-mid)].first);
				}
			}
		}
	}
	if(ans==INT_MAX)
	{
		cout<<-1;
	}
	else
	{
		cout<<ans;
	}
	return 0;
}