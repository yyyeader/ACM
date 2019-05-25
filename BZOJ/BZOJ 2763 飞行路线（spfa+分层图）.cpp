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
const int N=2e5+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,w;
}edge[M];

int cnt,n,m,k;
int head[N];
int dis[N][15];
bool vis[N][15];

void add(int u,int v,int w){
	edge[cnt]=node{v,head[u],w};
	head[u]=cnt++;
}

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void spfa(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	queue<pii>q;
	dis[st][0]=0;
	q.push(pii(0,st));
	while(!q.empty()){
		int u=q.front().second;
		int num=q.front().first;
		q.pop();
		vis[u][num]=false;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(dis[u][num]+t.w<dis[t.to][num]){
				dis[t.to][num]=dis[u][num]+t.w;
				if(!vis[t.to][num]){
					vis[t.to][num]=true;
					q.push(pii(num,t.to));
				}
			}
			if(num+1<=k&&dis[u][num]<dis[t.to][num+1]){
				dis[t.to][num+1]=dis[u][num];
				if(!vis[t.to][num+1]){
					vis[t.to][num+1]=true;
					q.push(pii(num+1,t.to));
				}
			}
		}
	}
}

int main(){
	while(~scanf("%d%d%d",&n,&m,&k)){
		init();
		int st,en;
		scanf("%d%d",&st,&en);
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		spfa(st);
		int ans=INF;
		for(int i=0;i<=k;i++){
			ans=min(ans,dis[en][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

