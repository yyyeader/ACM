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
const int N=2e2+5;
const int M=4e4+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
}edge[M*2];

int cnt,st,en;
int head[N],dep[N],d[N],low[M];//d[u]为顶点u出边下界和-入边下界和,low[i]记录第i条边的下界 

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	memset(d,0,sizeof(d));
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

int dinic(){
	int ans=0;
	while(bfs()){
		while(int d=dfs(st,INF))
			ans+=d;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		init();
		st=0,en=n+1;
		for(int i=1;i<=m;i++){
			int u,v,c;
			scanf("%d%d%d%d",&u,&v,&low[i],&c);
			link(u,v,c-low[i]);
			d[u]+=low[i];
			d[v]-=low[i];
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(d[i]<0) link(st,i,-d[i]);
			else{
				sum+=d[i];
				link(i,en,d[i]);
			}
		}
		if(sum!=dinic()) puts("NO");
		else{
			puts("YES");
			for(int i=2;i<=2*m;i+=2){
				printf("%d\n",edge[i^1].flow+low[i>>1]);
			}
		}
		puts("");
	}
	return 0;
}
