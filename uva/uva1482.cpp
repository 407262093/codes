#include <bits/stdc++.h>
using namespace std;
long long SG(long long x){
	return x%2 == 0 ? x/2 : SG(x/2);
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--){	
		int n;
		long long a,v = 0;
		cin>>n ;
		for(int i = 0;i<n;i++){
			cin>>a;
			v^=SG(a);
		}
		if(v)
			cout<<"YES/n";
		else
			cout<<"NO/n";
	}
	return 0;
}