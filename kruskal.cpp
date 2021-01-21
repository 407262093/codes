#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

struct Edge {
	int u, v, w;
	bool operator < (const Edge &other) const {
		return w < other.w;
	}
};//from to weight

int n, m;
int arr[MAXN];
vector <Edge> edges;

int find(int x) {
	if (arr[x] < 0) {
		return x;
	}
	return arr[x] = find(arr[x]);
}
void uni(int a,int b){
	a = find(a);
	b = find(b);
	if(a == b){
		return;
	}
	if(arr[a]>arr[b]){
		swap(a,b);
	}
	arr[a] += arr[b];
	arr[b] = a;
}
int main(int argc, char const *argv[])
{
	int u,v,w,ans,cnt;
	while(cin>>n>>m){
		if(n == 0&&m == 0) break;
		edges.clear();
		ans = 0;
		cnt = 0;
		for (int i = 0; i < m; i++)
		{
			cin>>u>>v>>w;
			edges.push_back({u,v,w});
		}
		for (int i = 0; i < n; i++) {
			arr[i] = -1;
		}
		sort(edges.begin(),edges.end());
		for (auto e : edges) {
			if (find(e.u) != find(e.v)) {
				ans += e.w;
				uni(e.u, e.v);
				cnt++;
			}
		}
		if (cnt != n - 1) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}
	return 0;
}
