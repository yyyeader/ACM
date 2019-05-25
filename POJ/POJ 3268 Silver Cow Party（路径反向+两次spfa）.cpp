#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=1e3+5;
const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct edge{
	int to,cost;
	edge(){}
	edge(int to,int cost){
		this->to=to;
		this->cost=cost;
	}
};
vector<edge>v[N];
int V,E;
int dis[N],sum[N],a[M],b[M],c[M];
bool vis[N];

void spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=0;i<v[k].size();i++){
			edge t=v[k][i];
			if(dis[k]+t.cost<dis[t.to]){
				dis[t.to]=dis[k]+t.cost;
				if(!vis[t.to]){
					q.push(t.to);
					vis[t.to]=true;
				}
			}
		}
	}
}

int main(){
	int s;
	scanf("%d%d%d",&V,&E,&s);
	for(int i=1;i<=E;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		v[a[i]].push_back(edge(b[i],c[i]));
	}
	spfa(s);
	for(int i=1;i<=V;i++){
		v[i].clear();
		if(dis[i]!=INF)
			sum[i]=dis[i];
	}
	for(int i=1;i<=E;i++){
		v[b[i]].push_back(edge(a[i],c[i]));
	}
	//将路径方向反向，即可计算其他各点到起点的最短距离 
	spfa(s);
	int ans=0;
	for(int i=1;i<=V;i++){
		if(dis[i]!=INF)
			sum[i]+=dis[i];
		ans=max(ans,sum[i]);
	}
	printf("%d\n",ans);
	return 0;
}
