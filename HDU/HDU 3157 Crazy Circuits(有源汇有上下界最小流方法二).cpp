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
const int N=1e2+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
}edge[2*M];

int cnt,st,en;
int head[N],dep[N],out[N],in[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	memset(out,0,sizeof(out));
	memset(in,0,sizeof(in));
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
	if(en==u) return fl;
	int tmp=0;
	for(int i=head[u];i&&fl;i=edge[i].next){
		node &t=edge[i];
		if(t.flow&&dep[u]+1==dep[t.to]){
			int x=dfs(t.to,min(t.flow,fl));
			if(x>0){
				t.flow-=x;
				edge[i^1].flow+=x;
				fl-=x;
				tmp+=x;
			}
		}
	}
	if(!tmp) dep[u]=-2;
	return tmp;
}

int dinic(int S,int T){
	st=S,en=T;
	int ans=0;
	while(bfs()){
		while(int d=dfs(st,INF)) ans+=d;
	}
	return ans;
}

void del(int u){
	for(int i=head[u];i;i=edge[i].next) edge[i].flow=edge[i^1].flow=0;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		init();
		int S=0,T=n+1,SS=n+2,TT=n+3;
		for(int i=1;i<=m;i++){
			char s1[10],s2[10];
			int u,v,low;
			scanf("%s%s%d",s1,s2,&low);
			if(s1[0]=='+') u=S;
			else sscanf(s1,"%d",&u);
			if(s2[0]=='-') v=T;
			else sscanf(s2,"%d",&v);
			link(u,v,INF);
			out[u]+=low;
			in[v]+=low;
		}
		int sum=0;
		for(int i=S;i<=T;i++){
			int tmp=in[i]-out[i];
			if(tmp>0) link(SS,i,tmp),sum+=tmp;
			else if(tmp<0) link(i,TT,-tmp);
		}
		link(T,S,INF);
		int ans=dinic(SS,TT);
		if(ans==sum){
			del(SS),del(TT);
			int tflow=edge[cnt-1].flow;
			edge[cnt-1].flow=edge[cnt-2].flow=0;
			ans=dinic(T,S);
			printf("%d\n",tflow-ans);
		}
		else puts("impossible");
	}
	return 0;
}

