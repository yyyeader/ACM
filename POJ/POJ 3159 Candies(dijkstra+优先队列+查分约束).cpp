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
const int N=3e4+5;
const int M=2e5+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,w;
}edge[M];

int cnt;
int head[N],dis[N];
bool vis[N];

void init(){
	cnt=1;
	memset(head,0,sizeof(head));
}

void add(int u,int v,int w){
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].w=w;
	head[u]=cnt++;
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
		for(int i=head[u];i;i=edge[i].next) {
			node t=edge[i];
			if(d+t.w<dis[t.to]){
				dis[t.to]=d+t.w;
				q.push(pii(dis[t.to],t.to));
			}
		}
	}
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		dij(1);
		printf("%d\n",dis[n]);
	}
	return 0;
}

