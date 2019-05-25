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
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;
struct node{
	int next,to,flow;
}edge[M*2];

int cnt,st,en;
int head[N],dep[N],a[N],b[N];;

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void link(int u,int v,int flow){
	edge[cnt]=node{head[u],v,flow};
	head[u]=cnt++;
	edge[cnt]=node{head[v],u,0};
	head[v]=cnt++;
}

bool bfs(){
	memset(dep,0,sizeof(dep));
	queue<int>q;
	dep[st]=1;
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
	for(int i=head[u];i&&tmp<fl;i=edge[i].next){
		node &t=edge[i];
		if(t.flow&&dep[t.to]==dep[u]+1){
			int x=dfs(t.to,min(t.flow,fl));
			if(x>0){
				t.flow-=x;
				edge[i^1].flow+=x;
				tmp+=x;
			}
		}
	}
	if(!tmp) dep[u]=-2;
	return tmp;
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
		init();
		int n;
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		rep(i,1,n) scanf("%d",&b[i]);
		st=0,en=n*2+1;
		int sum=0;
		rep(i,1,n){
			if(!a[i]||a[i]&&!b[i]){	//0表示不回家,坑惨我了、、、 
				sum++;
				link(st,i,1);		//st->在校生和外来的 
			}
			if(a[i]){	
				link(i+n,en,1);		//学校里的床->en
				link(i,i+n,1);		//学校的学生->自己的床 
			}
		}
		rep(i,1,n){
			rep(j,1,n){
				int x;
				scanf("%d",&x);
				if(x)
					link(i,j+n,1);	//a认识b,a->b的床 
			}
		}
		if(dinic()==sum)
			puts("^_^");
		else
			puts("T_T");
	}
	return 0;
}

