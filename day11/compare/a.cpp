#include<bits/stdc++.h>
using namespace std;
string a,b;
int n;
int main(){
	freopen("compare.in","r",stdin);
	freopen("compare.out","w",stdout);
	cin>>n;
	cin>>a>>b;
	if(a==b)
	{
		cout<<"-1";
	}
	else if(a<b)
	{
		cout<<'F';
	}
	else
	{
		cout<<"Y";
	}
	return 0;
}