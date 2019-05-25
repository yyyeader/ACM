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
const int N=2e2+5;
const int M=1e3+5;
const int INF=0x3f3f3f3f;

struct node{
	int next,to,flow;
}edge[M*2];

int n,m,cnt,st,en;
int head[N],dep[N],cur[N],q[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void link(int u,int v,int flow){
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].flow=flow;
	head[u]=cnt++;
	edge[cnt].next=head[v];
	edge[cnt].to=u;
	edge[cnt].flow=0;
	head[v]=cnt++;
}

bool bfs(){
	memset(dep,0,sizeof(dep));
	int t=0,w=1;
	dep[st]=1;
	q[++t]=st;
	while(t<=w){
		int u=q[t++];
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow&&!dep[t.to]){
				dep[t.to]=dep[u]+1;
				q[++w]=t.to;
			}
		}
	}
	return dep[en];
}

int dfs(int u,int fl){
	if(en==u) return fl;
	for(int i=head[u];i;i=edge[i].next){
		node &t=edge[i];
		if(t.flow&&dep[t.to]==dep[u]+1){
			int x=dfs(t.to,min(t.flow,fl));
			if(x>0){
				t.flow-=x;
				edge[i^1].flow+=x;
				return x;
			}
		}
	}
	dep[u]=-2;
	return 0;
}

int dinic(){
	int ans=0;
	while(bfs()){
		while(int d=dfs(st,INF)) ans+=d;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&st,&en);
		init();
		rep(i,1,m){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			link(a,b,c*(m+1)+1);
		}
		int max_flow=dinic();
		printf("%d\n",max_flow%(m+1));//最小割(最大流)为max_flow/(m+1),最小割最小边数为max_flow%(m+1) 
	}
	return 0;
}

