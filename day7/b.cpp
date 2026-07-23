#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[5]={0,1,2,2,4};
	int k=unique(a+1,a+5)-a;
	cout<<k<<endl;
	return 0;
}