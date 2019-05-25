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
const int N=2e3+5;
const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
}edge[M*2];

int cnt,st,en;
int head[N],dep[N],out[N],in[N],low[M],G[N],D[N];

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
		if(t.flow&&dep[t.to]==dep[u]+1){
			int x=dfs(t.to,min(t.flow,fl));
			if(x>0){
				tmp+=x;
				fl-=x;
				t.flow-=x;
				edge[i^1].flow+=x;
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
		while(int d=dfs(st,INF))
			ans+=d;
	}
	return ans;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		init();
		int S=0,T=n+m+1,SS=n+m+2,TT=n+m+3;
		for(int i=1;i<=m;i++) scanf("%d",&G[i]);
		int num=0,sum=0;
		for(int i=1;i<=n;i++){
			int C;
			scanf("%d%d",&C,&D[i]);
			for(int j=1;j<=C;j++){
				int id,l,r;
				scanf("%d%d%d",&id,&l,&r);
				id++;
				link(i,id+n,r-l);
				low[++num]=l;
				out[i]+=l;
				in[id+n]+=l;
			}
		}
		link(T,S,INF);
		for(int i=1;i<=n;i++){
			link(S,i,D[i]);	 //D[i]是上限,下限为0,因为每天最多拍D[i]张照片 
		}
		for(int i=1;i<=m;i++){
			link(i+n,T,INF);//G[i]是下限,因为每个人至少要G[i]张照片 
			in[T]+=G[i];
			out[i+n]+=G[i];
		}
		for(int i=0;i<=n+m+1;i++){
			int tmp=in[i]-out[i];
			if(tmp>0)	link(SS,i,tmp),sum+=tmp;
			else if(tmp<0)	link(i,TT,-tmp);
		}
		int ans=dinic(SS,TT);
		if(ans==sum){
			ans=dinic(S,T);
			printf("%d\n",ans);
			for(int i=1;i<=num;i++){
				printf("%d\n",edge[i*2+1].flow+low[i]);
			}
		}
		else
			puts("-1");
		puts("");
	}
	return 0;
}

