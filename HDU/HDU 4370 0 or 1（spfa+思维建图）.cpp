#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
const int N=3e2+5;
const int INF=0x3f3f3f3f;

int n;
int cost[N][N],dis[N];
bool vis[N];

int spfa(int s,int e){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	queue<int>q;
	if(s==e){
		for(int i=1;i<=n;i++){
			if(i!=s){
				q.push(i);
				dis[i]=cost[s][i];
				vis[i]=true;
			}
		}
	}
	else{
		dis[s]=0;
		q.push(s);
	}
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
	return dis[e];
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&cost[i][j]);
			}
		}
		int ans=min(spfa(1,n),spfa(1,1)+spfa(n,n));
		printf("%d\n",ans);
	}
	return 0;
}
