#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int func(int i,int j){
	if(dp[i+1][j] <= dp[i][j-1]){
		return (min(dp[i+1][j],dp[i+1][j-1]))+1;	
	}
	else {
		return (min(dp[i][j-1],dp[i+1][j-1]))+1;
	}
}
int main(int argc, char const *argv[])
{
	int test;
	string str;
	cin>>test;
	getline(cin,str);
	int m = 1;
	while(test--){
		getline(cin,str);
		int len = str.length();
		
		for(int i = 0;i<len;i++){
			dp[i][i] = 0;
			if(i != 0) dp[i][i-1] = 0;
			else dp[i][0] = 0;
		}
            for(int i = 1;i<len;i++){
            	for(int k = 0;(k+i)<len;k++){
          	            	if(str[k] == str[k+i]){
	            		dp[k][k+i] = dp[k+1][k+i-1];
					}
					else{
						dp[k][k+i] = func(k,k+i);
					}
				}
			}
		cout<<"Case "<<m<<": "<<dp[0][len-1]<<endl;
		m+=1;
	}
	return 0;
}