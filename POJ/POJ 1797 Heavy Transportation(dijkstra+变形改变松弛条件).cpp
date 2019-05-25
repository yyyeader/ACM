#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+5;
const int INF=0x3f3f3f3f;

int V,E;
int cost[N][N],dis[N];
bool vis[N];

void dij(int s){
	memset(dis,-1,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[s]=INF;
	while(1){
		int k=-1;
		for(int i=1;i<=V;i++){
			if(!vis[i]&&(k==-1||dis[k]<dis[i]))
				k=i;
		}
		if(k==-1) break;
		vis[k]=true;
		for(int i=1;i<=V;i++){
			if(cost[k][i]==INF)
				continue;
			int mdis=min(dis[k],cost[k][i]);
			if(dis[i]<mdis)
				dis[i]=mdis;
		}
	}
}

int main(){
	int q,cas=0;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&V,&E);
		memset(cost,0x3f,sizeof(cost));
		for(int i=1;i<=E;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			cost[a][b]=cost[b][a]=min(cost[a][b],c);
		}
		dij(1);
		printf("Scenario #%d:\n%d\n\n",++cas,dis[V]);
	}
	return 0;
}
