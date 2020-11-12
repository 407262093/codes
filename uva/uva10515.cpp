#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[10][5];

	arr [1][0] = 1;
	arr [1][1] = 1;
	arr [1][2] = 1;
	arr [1][3] = 1;
	arr [2][0] = 2;
	arr [2][1] = 4;
	arr [2][2] = 8;
	arr [2][3] = 6;
	arr [3][0] = 3;
	arr [3][1] = 9;
	arr [3][2] = 7;
	arr [3][3] = 1;
	arr [4][0] = 4;
	arr [4][1] = 6;
	arr [4][2] = 4;
	arr [4][3] = 6;
	arr [5][0] = 5;
	arr [5][1] = 5;
	arr [5][2] = 5;
	arr [5][3] = 5;
	arr [6][0] = 6;
	arr [6][1] = 6;
	arr [6][2] = 6;
	arr [6][3] = 6;
	arr [7][0] = 7;
	arr [7][1] = 9;
	arr [7][2] = 3;
	arr [7][3] = 1;
	arr [8][0] = 8;
	arr [8][1] = 4;
	arr [8][2] = 2;
	arr [8][3] = 6;
	arr [9][0] = 9;
	arr [9][1] = 1;
	arr [9][2] = 9;
	arr [9][3] = 1;
	string st1,st2;
	while(cin>>st1>>st2){
		if(st1 == "0"&&st2 == "0"){
			break;
		}
		int a1 = st1[st1.length()-1]-48;
		int a2 = st2[st2.length()-1]-48;
		if(a2 == 0){
			cout<<0;
		}
		else {
			if(st2.length() != 1;){
				int a3 = st2[st2.length()-2]-48;
				a3=a3*10;
				a2+=a3;
			}
			cout<<arr[a1][a2%4]<<endl;
		}
	}


	return 0;
}
