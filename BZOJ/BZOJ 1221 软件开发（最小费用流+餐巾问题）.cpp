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
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=2e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow,cost;
}edge[M*2];

int cnt,st,en;
int head[N],dis[N],pre[N],h[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	memset(h,0,sizeof(h));
}

void link(int u,int v,int flow,int cost){
	edge[cnt]=node{v,head[u],flow,cost};
	head[u]=cnt++;
	edge[cnt]=node{u,head[v],0,-cost};
	head[v]=cnt++;
}

bool dij(){
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push(pii(0,st));
	while(!q.empty()){
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if(d>dis[u]) continue;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow&&dis[t.to]>dis[u]+t.cost+h[u]-h[t.to]){
				dis[t.to]=dis[u]+t.cost+h[u]-h[t.to];
				pre[t.to]=i;
				q.push(pii(dis[t.to],t.to));
			}
		}
	}
	return dis[en]!=INF;
}

void mcmf(int &flow,int &cost){
	flow=cost=0;
	while(dij()){
		int mmin=INF;
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			mmin=min(mmin,edge[i].flow);
		}
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			edge[i].flow-=mmin;
			edge[i^1].flow+=mmin;
			cost+=mmin*edge[i].cost;
		}
		for(int i=st;i<=en;i++) h[i]+=dis[i];
		flow+=mmin;
	}
}

int main(){
	int n,a,b,f,fA,fB;
	while(~scanf("%d%d%d%d%d%d",&n,&a,&b,&f,&fA,&fB)){
		init();
		st=0,en=2*n+1;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			link(st,i,x,f);
			link(st,i+n,x,0);
			link(i,en,x,0);
			if(i+1<=n) link(i,i+1,INF,0);//第i天没用完可以留给下一天(比如说第p天通过A消毒留了6条毛巾给第i天,但是第i天只用5条,可以留给第i+1天一条)
			if(i+a+1<=n) link(i+n,i+a+1,INF,fA);
			if(i+b+1<=n) link(i+n,i+b+1,INF,fB);
		}
		int flow,cost;
		mcmf(flow,cost);
		printf("%d\n",cost);
	}
	return 0;
}

