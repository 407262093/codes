#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 10005;
int fol[MAXN][MAXN];

void init(int n){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			fol[i][j] = INF;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,m,f,t,w;
	while(cin>>n>>m){//n表示有幾個點 m表示有幾條線
		if(n<=0) break;
		init(n);
		for(int i = 0;i<m;i++){
			cin>>f>>t>>w;
			fol[f][t] = w;
			fol[t][f] = w;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				for(int k = 1;k <= n;k++){
					if(k == j){
						fol[j][k] = 0;
						continue;
					} 
					if(i == k) continue;
					if(fol[j][k] > fol[i][k] + fol[j][i]){
						fol[j][k] = fol[i][k] + fol[j][i];
					}
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				cout<<fol[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}