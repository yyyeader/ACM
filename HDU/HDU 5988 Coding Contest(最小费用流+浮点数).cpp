#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<double,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e2+5;
const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
	double cost;
}edge[M*2]; 

int cnt,st,en,n,m;
int head[N],pre[N];
double dis[N];//dis[i]表示到dis[i]为止不破坏电线的最大概率
bool vis[N];

int sgn(double x) { return x < -eps? -1: x > eps; }

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
} 

void link(int u,int v,int flow,double cost){
	edge[cnt]=node{v,head[u],flow,cost};
	head[u]=cnt++;
	edge[cnt]=node{u,head[v],0,-cost};
	head[v]=cnt++;
}

bool spfa() {
	memset(pre,0,sizeof(pre));
	memset(vis,false,sizeof(vis));
	for(int i=st;i<=en;i++) dis[i]=INF;
	dis[st]=0;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow&&dis[t.to]>dis[u]+t.cost+eps){
				dis[t.to]=dis[u]+t.cost;
				pre[t.to]=i;
				if(!vis[t.to]){
					vis[t.to]=true;
					q.push(t.to);
				}
			}
		}
	}
	if(dis[en]==INF)
		return false;
	return true;
}

void mcmf(int &flow,double &cost){
	while(spfa()){
		int mmin=INF;
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			mmin=min(mmin,edge[i].flow);
		}
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			edge[i].flow-=mmin;
			edge[i^1].flow+=mmin;
			cost+=edge[i].cost*mmin;
		}
		flow+=mmin;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		st=0,en=n+1;
		for(int i=1;i<=n;i++){
			int s,b;
			scanf("%d%d",&s,&b);
			if(s-b>0) link(st,i,s-b,0);
			if(s-b<0) link(i,en,b-s,0);
		}
		for(int i=1;i<=m;i++){
			int u,v,flow;
			double p;
			scanf("%d%d%d%lf",&u,&v,&flow,&p);
			p=-log(1-p);
			if(flow>0) link(u,v,1,0);
			if(flow>1) link(u,v,flow-1,p);
		}
		int flow=0;
		double cost=0;
		mcmf(flow,cost);
		cost=exp(-cost);
		printf("%.2f\n",1-cost);
	}
	return 0;
}

