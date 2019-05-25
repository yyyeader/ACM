#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int next,to,flow;
}edge[M];

int cnt,st,en;
int mp[105][105],dep[N],head[N];
int d[4][2]={0,1,1,0,0,-1,-1,0};

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void link(int u,int v,int flow){
	edge[cnt]=node{head[u],v,flow};
	head[u]=cnt++;
	edge[cnt]=node{head[v],u,0};
	head[v]=cnt++;
}

bool bfs(){
	memset(dep,0,sizeof(dep));
	dep[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow&&!dep[t.to]){
				dep[t.to]=dep[u]+1;
				q.push(t.to);
			}
		}
	}
	return dep[en];
}

int dfs(int u,int fl){
	if(u==en) return fl;
	int tmp=0;
	for(int i=head[u];i&&tmp<fl;i=edge[i].next){
		node &t=edge[i];
		if(t.flow&&dep[t.to]==dep[u]+1){
			int x=dfs(t.to,min(t.flow,fl));
			t.flow-=x;
			edge[i^1].flow+=x;
			tmp+=x;
		}
	}
	if(!tmp) dep[u]=-2;
	return tmp;
}

int dinic(){
	int ans=0;
	while(bfs()){
		while(int d=dfs(st,INF))
			ans+=d;
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	//st->ÀÇ, ÀÇ->0, 0->0, 0->ÀÇ, 0->Ñò, ÀÇ->Ñò, Ñò->en 
	st=0,en=n*m+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==2) continue;
			for(int k=0;k<4;k++){
				int xx=i+d[k][0];
				int yy=j+d[k][1];
				if(mp[i][j]==1&&mp[xx][yy]==1) continue;
				if(xx>=1&&yy>=1&&xx<=n&&yy<=m){
					link((i-1)*m+j,(xx-1)*m+yy,1);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==1) link(st,(i-1)*m+j,INF);
			if(mp[i][j]==2) link((i-1)*m+j,en,INF);
		}
	}
	cout<<dinic()<<endl;
	return 0;
}

