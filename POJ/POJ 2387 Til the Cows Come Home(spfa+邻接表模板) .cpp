#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e3+5;
const int INF=0x3f3f3f3f;

struct edge{
	int to,cost;
	edge(int to,int cost){
		this->to=to;
		this->cost=cost;
	}
};

vector<edge>adj[N];
int V,E,dis[N];
bool vis[N];

void spfa(int s){
	for(int i=1;i<=V;i++){
		dis[i]=INF;
	}
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		vis[p]=false;
		for(int i=0;i<adj[p].size();i++){
			edge t=adj[p][i];
			if(dis[p]+t.cost<dis[t.to]){
				dis[t.to]=dis[p]+t.cost;
				if(!vis[t.to]){
					q.push(t.to);
					vis[t.to]=true;
				}
			}
		}
	}
}

int main(){
	scanf("%d%d",&E,&V);
	for(int i=1;i<=E;i++){
		int a,b,cost;
		scanf("%d%d%d",&a,&b,&cost);
		adj[a].push_back(edge(b,cost));
		adj[b].push_back(edge(a,cost));
	}
	spfa(1);
	printf("%d\n",dis[V]);
	return 0;
}
