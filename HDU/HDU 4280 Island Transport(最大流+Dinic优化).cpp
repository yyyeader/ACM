#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
const int M=2e5+5;

struct node{
	int to,next,flow;
}edge[M*2];

int n,m,cnt,st,en;
int head[N],dep[N],cur[N],que[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void addedge(int u,int v,int flow){
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].flow=flow;
	head[u]=cnt++;
	
	edge[cnt].next=head[v];
	edge[cnt].to=u;
	edge[cnt].flow=flow;
	head[v]=cnt++;
}

bool bfs(){
	memset(dep,0,sizeof(dep));
	dep[st]=1;
	int hd=0,tl=0;
	que[tl++]=st;
	while(hd<tl){
		int u=que[hd];
		hd++;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow&&!dep[t.to]){
				dep[t.to]=dep[u]+1;
				que[tl++]=t.to;
			}
		}
	}
	return dep[en];
}

int dfs(int u,int fl){
	if(u==en) return fl;
	int tmp=0; 
	for(int &i=cur[u];i&&fl-tmp>0;i=edge[i].next){//fl-tmp为多路增广优化,cur[]为当前弧优化
		node &t=edge[i];
		if((dep[t.to]==dep[u]+1)&&t.flow!=0){
			int x=dfs(t.to,min(fl,t.flow));
			if(x>0){
				t.flow-=x;
				edge[i^1].flow+=x;
				tmp+=x;
				return x;
			}
		}
	}
	if(!tmp) dep[u]=-2;//炸点优化 
	return 0;
}

int dinic(){
	int ans=0;
	while(bfs()){
		for(int i=1;i<=n;i++) cur[i]=head[i];
		while(int d=dfs(st,INF))
			ans+=d;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		int mmin=INF,mmax=-INF;
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x<mmin){
				mmin=x;
				st=i;
			}
			if(x>mmax){
				mmax=x;
				en=i;
			}
		}
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
		}
		printf("%d\n",dinic());
	}
	return 0;
}

