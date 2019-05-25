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
const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,w;
}edge[M*25];

int cnt,n,m,k,st,en;
int head[N*12],dis[N*12];
bool vis[N*12];

void add(int u,int v,int w){
	edge[cnt]=node{v,head[u],w};
	head[u]=cnt++;
}

void init(){
	cnt=1;
	memset(head,0,sizeof(head));
}

void dij(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push(pii(0,st));
	while(!q.empty()){
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(d+t.w<dis[t.to]){
				dis[t.to]=d+t.w;
				q.push(pii(dis[t.to],t.to));
			}
		}
	}
}

int main(){
	while(~scanf("%d%d%d%d%d",&n,&m,&k,&st,&en)){
		init();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			for(int j=0;j<=k;j++){
				add(u+j*n,v+j*n,w);
				add(v+j*n,u+j*n,w);
				if(j<k){
					add(u+j*n,v+(j+1)*n,0);
					add(v+j*n,u+(j+1)*n,0);
				}
			}
		}
		dij(st);
		int ans=INF;
		for(int i=0;i<=k;i++){
			ans=min(ans,dis[en+i*n]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

