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
const int N=5e2+5;
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

void mcmf(int &flow,int &cost){
	flow=cost=0;
	while(spfa()){
		int mmin=INF;
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			mmin=min(mmin,edge[i].flow);
		}
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			edge[i].flow-=mmin;
			edge[i^1].flow+=mmin;
			//cout<<edge[i^1].flow<<" from="<<edge[i^1].to<<" to="<<edge[i].to<<" mmin="<<mmin<<endl;
			cost+=edge[i].cost*mmin;
		}
		flow+=mmin;
		//cout<<flow<<" "<<cost<<endl; 
	}
}



int main(){
	int n;
	while(~scanf("%d",&n)){
		init();
		st=0,en=n+1;
		for(int i=1;i<=n;i++){
			int x,to,cost;
			scanf("%d",&x);
			for(int j=1;j<=x;j++){
				scanf("%d%d",&to,&cost);
				link(i,to,INF,cost);
				link(st,to,1,cost);//对应in[to]-out[to]
			}
			link(i,1,INF,0);
			link(i,en,x,0);//对应out[i]-in[i] 
		}
		int flow=0,cost=0;
		mcmf(flow,cost);
		printf("%d\n",cost);
	}
	return 0;
}

