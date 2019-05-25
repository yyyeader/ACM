#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e4+5;
const int M=2e4+5;
const int INF=0x3f3f3f3f;

struct node{
	int next,to,w;
}edge[M];

int cnt,n,m,q;
int vis[N],head[N],dep[N],dis[N],f[N][30];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	memset(dep,0,sizeof(dep));
	memset(f,0,sizeof(f));
}

void add(int u,int v,int w){
	edge[cnt]=node{head[u],v,w};
	head[u]=cnt++;
}

void dfs(int u,int rt){
	vis[u]=rt;
	for(int i=1;i<25;i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=edge[i].next){
		node t=edge[i];
		if(vis[t.to]) continue;
		dep[t.to]=dep[u]+1;
		dis[t.to]=dis[u]+t.w;
		f[t.to][0]=u;
		dfs(t.to,rt);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y); 
	int dc=dep[x]-dep[y];
	for(int i=0;i<25;i++){
		if((1<<i)&dc)
			x=f[x][i];
	}
	if(x==y) return x;
	for(int i=24;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

int main(){
	while(~scanf("%d%d%d",&n,&m,&q)){
		init();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i])
				dfs(i,i);
		}
		for(int i=1;i<=q;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(vis[x]!=vis[y])
				puts("Not connected");
			else
				printf("%d\n",dis[x]+dis[y]-2*dis[lca(x,y)]);
		}
	}
	return 0;
}

