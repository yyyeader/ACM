#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int N=3e3+5;
const int INF=0x3f3f3f3f;

int V,E,W;
int cost[N][N],dis[N],qcnt[N];
bool vis[N];

bool spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	memset(qcnt,0,sizeof(qcnt));
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=1;i<=V;i++){
			if(dis[k]+cost[k][i]<dis[i]){
				dis[i]=dis[k]+cost[k][i];
				if(!vis[i]){
					q.push(i);
					qcnt[i]++;
					if(qcnt[i]>=V){
						return true;
					}
					vis[i]=true;
				}
			}
		}
	}
	return false;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(cost,0x3f,sizeof(cost));
		scanf("%d%d%d",&V,&E,&W);
		int a,b,c;
		//注意普通边单向，虫洞双向 
		for(int i=1;i<=E;i++){			
			scanf("%d%d%d",&a,&b,&c);
			if(cost[a][b]>c)
				cost[a][b]=cost[b][a]=c;
		}
		for(int i=1;i<=W;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(cost[a][b]>-c)
				cost[a][b]=-c;
		}
		if(spfa(1))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
