#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
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
const int M=2e5+5;
const int INF=0x3f3f3f3f;

struct node{int next,to;}edge[2*M];
int cnt,scc,id;
int head[N],low[N],dfn[N],belong[N];
bool vis[N];
stack<int>sk;

void add(int u,int v){edge[cnt]=node{head[u],v};head[u]=cnt++;};

void init(){
	cnt=2;
	scc=id=0;
	while(!sk.empty()) sk.pop();
	memset(head,0,sizeof(head));
	memset(belong,0,sizeof(belong));
	memset(dfn,0,sizeof(dfn));
}

void tarjan(int u){
	dfn[u]=low[u]=++id;
	sk.push(u);
	for(int i=head[u];i;i=edge[i].next){
		int t=edge[i].to;
		if(!dfn[t]){
			tarjan(t);
			low[u]=min(low[u],low[t]);
		}
		else if(!belong[t]) low[u]=min(low[u],dfn[t]);
	}
	if(low[u]==dfn[u]){
		scc++;
		while(!sk.empty()){
			int t=sk.top();sk.pop();
			belong[t]=scc;
			if(t==u) break;
		}
	}
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		init();
		rep(i,1,m){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		tarjan(1);
		bool flag=true;
		rep(i,1,n)
			if(!dfn[i]) flag=false;
		if(flag&&scc==1)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}

