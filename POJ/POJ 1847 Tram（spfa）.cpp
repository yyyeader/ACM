#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e2+5;
const int INF=0x3f3f3f3f;

int n;
int cost[N][N],dis[N];
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
		for(int i=1;i<=n;i++){
			if(dis[k]+cost[k][i]<dis[i]){
				dis[i]=dis[k]+cost[k][i];
				if(!vis[i]){
					q.push(i);
					vis[i]=true;
				}
			}
		}
	}
}

int main(){
	memset(cost,0x3f,sizeof(cost));
	int a,b;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			if(j==1)
				cost[i][x]=0;
			else
				cost[i][x]=1;
		}
	}
	spfa(a);
	if(dis[b]!=INF)
		printf("%d\n",dis[b]);
	else
		puts("-1");
	return 0;
}
