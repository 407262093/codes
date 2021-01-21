#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 5;
struct Edge{
	int from, to, dist;
};
struct item{
	int d,u;//d表示edge長度 u表示哪個edge
	bool operator < (const item &rs) const{
		return d > rs.d;
	}
};
class dijkstra{
private:
	int n,m;
	vector<Edge>edges;
	vector<int>G[MAXN];
	bool visit[MAXN];
public:
	int d[MAXN];
	int p[MAXN];

	dijkstra(int n){
		this->n = n;
		for(int i = 0;i<n;i++){
			G[i].clear();
		}
		edges.clear();
	}
	void AddEdge(int from,int to,int dist){
		edges.push_back((Edge){from,to,dist});
		edges.push_back((Edge){to,from,dist});
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	void run_dijkstra(int s){
		priority_queue <item> pq;
		for(int i = 0;i<n;i++){
			d[i] = INF;
		}
		d[s] = 0;
		memset(visit,0,sizeof(visit));
		pq.push((item){0,s});
		while(!pq.empty()){
			item x = pq.top();
			pq.pop();
			int u = x.u;
			if(visit[u]) continue;
			visit[u] = true;
			for(int i = 0;i<G[u].size();i++){
				Edge e = edges[G[u][i]]; // Edge& e?
				int nowto,nowdist;
				nowto = e.to;
				nowdist = e.dist;//如果沒有額外放變數需要operator?
				if(d[nowto]>d[u]+nowdist){
					d[nowto] = d[u]+nowdist;
					p[nowto] = u;
					pq.push((item){d[nowto],nowto});
				}
			}
		}
	}
};
class dijkstra a(5);
int main(int argc, char const *argv[])
{
	a.AddEdge(1,2,2);
	a.AddEdge(1,3,3);
	a.AddEdge(2,4,4);
	a.AddEdge(3,4,5);
	a.run_dijkstra(1);
	for(int i = 1;i<5;i++){
		cout<<a.d[i]<<" ";
	}
	cout<<endl;
	for(int i = 1;i<5;i++){
		cout<<a.p[i]<<" ";
	}
	cout<<endl;
	return 0;
}