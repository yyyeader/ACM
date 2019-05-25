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
const int N=1e4+5;
const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
}edge[2*M];

int cnt,st,en;
int head[N],dep[N],in[N],out[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
}

void link(int u,int v,int flow){
	edge[cnt]=node{v,head[u],flow};
	head[u]=cnt++;
	edge[cnt]=node{u,head[v],0};
	head[v]=cnt++;
}

int bfs(){
	memset(dep,0,sizeof(dep));
	dep[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow&&!dep[t.to]){
				dep[t.to]=dep[u]+1;
				q.push(t.to);
			}
		}
	}
	return dep[en];
}

int dfs(int u,int fl){
	if(u==en) return fl;
	int tmp=0;
	for(int i=head[u];i&&fl;i=edge[i].next){
		node &t=edge[i];
		if(t.flow&&dep[t.to]==dep[u]+1){
			int x=dfs(t.to,min(t.flow,fl));
			if(x>0){
				t.flow-=x;
				edge[i^1].flow+=x;
				tmp+=x;
				fl-=x;
			}
		}
	}
	if(!tmp) dep[u]=-2;
	return tmp;
}

int dinic(int s,int t){
	st=s,en=t;
	int ans=0;
	while(bfs()){
		while(int d=dfs(st,INF)) ans+=d;
	}
	return ans;
}

int main(){
	int n,m,k,cas=0;
	while(~scanf("%d%d%d",&n,&m,&k)){
		init();
		int L,R;
		scanf("%d%d",&L,&R);
		int S=0,T=n+m+1,SS=n+m+2,TT=n+m+3;
		for(int i=1;i<=k;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			link(u,v+n,1);
		}
		for(int i=1;i<=n;i++){
			link(S,i,R-L);
			out[S]+=L;
			in[i]+=L;
		}
		for(int i=1;i<=m;i++){
			link(i+n,T,R-L);
			out[i+n]+=L;
			in[T]+=L;
		}
		link(T,S,INF);
		int sum=0;
		for(int i=S;i<=T;i++){
			int tmp=in[i]-out[i];
			if(tmp>0) link(SS,i,tmp),sum+=tmp;
			else if(tmp<0) link(i,TT,-tmp);
		}
		printf("Case %d: ",++cas);
		if(sum==dinic(SS,TT))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}

