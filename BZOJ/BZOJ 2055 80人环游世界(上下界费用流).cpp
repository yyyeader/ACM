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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow,cost;
}edge[M]; 

int cnt,st,en;
int head[N],dis[N],pre[N],out[N],in[N]; 
bool vis[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	memset(out,0,sizeof(out));
	memset(in,0,sizeof(in));
} 

void link(int u,int v,int flow,int cost){
	edge[cnt]=node{v,head[u],flow,cost};
	head[u]=cnt++;
	edge[cnt]=node{u,head[v],0,-cost};
	head[v]=cnt++;
}

bool spfa() {
	memset(dis,0x3f,sizeof(dis));
	memset(pre,0,sizeof(pre));
	memset(vis,false,sizeof(vis));
	dis[st]=0;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow&&dis[t.to]>dis[u]+t.cost){
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

void mcmf(int &flow,int &cost,int S,int T){
	flow=cost=0;
	st=S,en=T;
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
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		init();
		int S=0,SS=2*n+1,TT=2*n+2;
		for(int i=1;i<=n;i++){
			int val;
			scanf("%d",&val);
			link(S,i,INF,0);
			link(i,i+n,0,0);
			out[i]+=val;
			in[i+n]+=val;
		}
		link(SS,S,m,0);//总共有m个人，所以源点s最多流出m的流量 
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				int cost;
				scanf("%d",&cost);
				if(cost!=-1)
					link(i+n,j,INF,cost);
			}
		}
		for(int i=1;i<=2*n;i++){
			int tmp=in[i]-out[i];
			if(tmp>0) link(SS,i,tmp,0);
			if(tmp<0) link(i,TT,-tmp,0);
		}
		int flow,cost;
		mcmf(flow,cost,SS,TT);
		printf("%d\n",cost);
	}
	return 0;
}

