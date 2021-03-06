#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,w,next;
}edge[2*N];

int cnt;
int head[N],dis[N];
bool vis[N];

void add(int u,int v,int w){
	edge[cnt]=node{v,w,head[u]};
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
	dis[st]=0;
	q.push(pii(0,st));
	while(!q.empty()){
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if(dis[u]<d) continue;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(dis[u]+t.w<dis[t.to]){
				dis[t.to]=dis[u]+t.w;
				q.push(pii(dis[t.to],t.to));
			}
		}
	}
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n&&m){
		init();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		dij(1);
		printf("%d\n",dis[n]);
	}
	return 0;
}

