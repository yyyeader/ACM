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
const int N=5e4+5;
const int M=2e5+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,w;
}edge[M];

int cnt,n,m;
int head[N],dis[N];
bool vis[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void add(int u,int v,int w){
	edge[cnt]=node{v,head[u],w};
	head[u]=cnt++;
}

void spfa(int st){
	memset(dis,0x3f,sizeof(dis));
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
			if(dis[t.to]>t.w+dis[u]){
				dis[t.to]=t.w+dis[u];
				if(!vis[t.to]){
					vis[t.to]=true;
					q.push(t.to);
				}
			}
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(v,u-1,-w);
		}
		for(int i=1;i<=n;i++){
			add(i-1,i,1);
			add(i,i-1,0);
		}
		spfa(n);
		printf("%d\n",-dis[0]);
	}
	return 0;
}

