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
const int N=5e2+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow,cost;
}edge[M*2];

int cnt,st,en,n,m,s;
int head[N],dis[N],pre[N],h[N],need[N],pay[N];//pre记录spfa中的前驱

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
	memset(pre,0,sizeof(pre));
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
	while(dij()){
		int mmin=INF;
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			mmin=min(mmin,edge[i].flow);
		}
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			edge[i].flow-=mmin;
			edge[i^1].flow+=mmin;
			cost+=edge[i].cost*mmin;
		}
		for(int i=st;i<=en;i++) h[i]+=dis[i];
		flow+=mmin;
	}
}

int main(){
	while(~scanf("%d%d%d",&n,&m,&s)){
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&need[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&pay[i]);
		}
		st=0,en=2*n+1;
		for(int i=1;i<=n;i++){
			link(st,i,INF,pay[i]);
			link(i+n,en,need[i],0);
			link(i,i+n,s+need[i],0);//拆点限制库存，这里写S+need[i],原因是可以买need[i]卖掉，再买S存下留待以后用 
			if(i+1<=n)				//所以实际上i->i'的最大流量是need[i]+S 
				link(i+n,i+1,s,m);
		}
		int flow=0,cost=0; 
		mcmf(flow,cost);
		printf("%d\n",cost);
	}
	return 0;
}

