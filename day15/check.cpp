#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int i=1)
    {
        system("gen.exe");
		system("test.exe");
		if(system("fc test.out std.out"))
		{
			cout<<"WA";
			break;
		}
		else
		{
			cout<<"AC\n";
		}
    }
	return 0;
}