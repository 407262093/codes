#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 5;
struct Edge
{
	int from,to,weight;
	
};
struct item
{
	int wei,todo;
	bool operator < (const item &other) const{
		return wei > other.wei;
	}
};
vector <int> G[MAXN];
vector <Edge> edge;
bool visit[MAXN];
int d[MAXN];
int p[MAXN];
int main(){
	int n,m,f,t,w,beg,siz;
	while(cin>>n>>m){//n表示有幾個點 m表示有幾條線
		if(n <= 0) break;
		edge.clear();
		for(int i = 0;i<=n;i++){
			G[i].clear();
		}
		for(int i = 0;i<m;i++){//add edge
			cin>>f>>t>>w;
			edge.push_back((Edge){f,t,w});
			edge.push_back((Edge){t,f,w});
			siz = edge.size(); 
			G[f].push_back(siz-2);
			G[t].push_back(siz-1);
		}
		memset(visit,0,sizeof(visit));
		for(int i = 0;i<=n;i++){//初始化
			d[i] = INF;
		}

		cin>>beg;//從哪開始
		d[beg] = 0;
		priority_queue <item> pq;
		pq.push((item){0,beg});
		while(!pq.empty()){
			item x = pq.top();
			pq.pop();
			int u = x.todo;
			if(visit[u]) continue;
			visit[u] = true;
			for(int i = 0;i<G[u].size();i++){
				Edge e = edge[G[u][i]];
				int nowto,nowdist;
				nowto = e.to;
				nowdist = e.weight;
				if(d[nowto] > nowdist){
					d[nowto] = nowdist;
					p[nowto] = u;
					pq.push((item){d[nowto],nowto});
				}
			}
		}
		for(int i = 1;i<=n;i++){
			cout<<d[i]<<" ";
		}
		cout<<endl;
		for(int i = 1;i<=n;i++){
			cout<<p[i]<<" ";
		}
		cout<<endl;
	}
    return 0;
}