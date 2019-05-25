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

int n,m,k,st,en,cnt;
LL head[N],dis[20][N];//dis[i][j]表示花掉了i条免费边时到j点的最短路 
bool vis[20][N];

struct node{
	LL next,to,w;
}edge[M];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void add(LL u,LL v,LL w){
	edge[cnt]=node{head[u],v,w};
	head[u]=cnt++;
}

void spfa(LL st){
	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++)
			dis[i][j]=1e18;
	memset(vis,false,sizeof(vis));
	queue<pll>q;
	q.push(pll(0,st));
	dis[0][st]=0;
	while(!q.empty()){
		LL u=q.front().second;
		LL x=q.front().first;
		q.pop();
		vis[x][u]=false;
		for(LL i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(dis[x][u]+t.w<dis[x][t.to]){
				dis[x][t.to]=dis[x][u]+t.w;
				if(!vis[x][t.to]){
					vis[x][t.to]=true;
					q.push(pll(x,t.to));
				}
			}
			if(x+1<=k&&dis[x][u]<dis[x+1][t.to]){
				dis[x+1][t.to]=dis[x][u];
				if(!vis[x+1][t.to]){
					vis[x+1][t.to]=true;
					q.push(pii(x+1,t.to));
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d%d",&n,&m,&k,&st,&en);
	init();
	rep(i,1,m){
		LL a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	spfa(st);
	LL ans=1e18;
	rep(i,0,k)
		ans=min(ans,dis[i][en]);
	printf("%lld\n",ans);
	return 0;
}

