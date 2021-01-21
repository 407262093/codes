#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Edge
{
	int from,to,weight;
	bool operator < (const Edge &other) const{
		return weight < other.weight;
	}
};
int arr[MAXN];
vector <Edge> edge;
int find(int x){
	if(arr[x]<0){
		return x;
	}
	return arr[x] = find(arr[x]);
}

void uni(int a,int b){
	if(arr[a] < arr[b]){
		swap(a,b);
	}
	arr[a] += arr[b];
	arr[b] = a;
}

int main(){
	int n,m,f,t,w;
	int f1,f2,ans,cnt;
	while(cin>>n>>m){//n表示有幾個點 m表示有幾條線
		if(n <= 0) break;
		cnt = 0;
		ans = 0;
		edge.clear();
		for(int i = 0;i<m;i++){
			cin>>f>>t>>w;
			edge.push_back({f,t,w});
		}
		sort(edge.begin(),edge.end());
		for(int i = 0;i<n;i++){
			arr[i] = -1;
		}
		for(auto e :edge){
			f1 = find(e.from);
			f2 = find(e.to);
			if(f1 != f2){
				ans += e.weight;
				uni(f1,f2);
				cnt++;
			}
		}
		if(cnt != n-1) cout<<"-1";
		else cout<<ans;
		cout<<endl;
	}
    return 0;
}