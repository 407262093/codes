#include <bits/stdc++.h>

using namespace std;
int nodes[20000+5];
int index[20000+5];
int len = 0;
int find_root(int num){
	if(nodes[num]==num){
		cout<<len<<endl;
		len = 0;
	}
	else{
		len	+=index[num];
		find_root(nodes[num]);
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		for(int i = 1; i < n ;i++){
			nodes[i] = i;
			index[i] = 0;
		}
		char en;
		int num1,num2;
		while(cin>>en){
			if(en == 'O') break;
			else if(en == 'E'){
				cin>>num1;
				find_root(num1);
			}
			else if(en == 'I'){
				cin>>num1>>num2 ;
				nodes[num1] = num2 ;
				index[num1] = abs(num1-num2);
			}
		}
	}
	return 0;
}
