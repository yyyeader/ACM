#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=2e2+5;
const int M=2e4+5;
const int INF=0x3f3f3f3f;

struct point{
	int x,y;
}a[N],b[N];

struct node{
	int next,to,cap,flow,cost;
}edge[M<<1];

int cnt,st,en;
int head[N],dis[N],pre[N];
char mp[N][N];
bool vis[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void link(int u,int v,int cap,int cost){
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].flow=0;
	edge[cnt].cap=cap;
	edge[cnt].cost=cost;
	head[u]=cnt++;
	
	edge[cnt].next=head[v];
	edge[cnt].to=u;
	edge[cnt].flow=0;
	edge[cnt].cap=0;
	edge[cnt].cost=-cost;
	head[v]=cnt++;
}

bool spfa(){
	memset(dis,0x3f,sizeof(dis));
	memset(pre,0,sizeof(pre));
	memset(vis,false,sizeof(vis));
	queue<int>q;
	dis[st]=0;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.cap>t.flow&&dis[t.to]>dis[u]+t.cost){
				dis[t.to]=dis[u]+t.cost;
				pre[t.to]=i;
				if(!vis[t.to]){
					vis[t.to]=true;
					q.push(t.to);
				}
			}
		}
	}
	return pre[en];
}

void mcmf(int &flow,int &cost){
	flow=0,cost=0;
	while(spfa()){
		int mmin=INF;
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			if(mmin>edge[i].cap-edge[i].flow)
				mmin=edge[i].cap-edge[i].flow;
		}
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			edge[i].flow+=mmin;
			edge[i^1].flow-=mmin;
			cost+=edge[i].cost*mmin;
		}
		flow+=mmin;
	}
}

int main(){
	FAST_IO;
	int n,m;
	while(scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		init();
		int nx=0,ny=0;
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=m;j++){
				if(mp[i][j]=='m') a[++nx]=point{i,j};
				else if(mp[i][j]=='H') b[++ny]=point{i,j};
			}
		}
		st=0,en=nx+ny+1;
		for(int i=1;i<=nx;i++) link(st,i,1,0);
		for(int i=1;i<=nx;i++){
			for(int j=1;j<=ny;j++){
				int cost=abs(a[i].x-b[j].x)+abs(a[i].y-b[j].y);
				link(i,j+nx,1,cost);
			}
		}
		for(int i=1;i<=ny;i++) link(i+nx,en,1,0);
		int flow,cost;
		mcmf(flow,cost);
		printf("%d\n",cost);
	}
	return 0;
} 
