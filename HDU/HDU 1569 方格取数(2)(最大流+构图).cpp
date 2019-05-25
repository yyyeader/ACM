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
const int N=3e3+5;
const int M=2e4+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
}edge[M*2];

int cnt,st,en;
int d[4][2]={-1,0,0,-1,1,0,0,1};
int head[N],dep[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
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

int dinic(){
	int ans=0;
	while(bfs()){
		while(int d=dfs(st,INF)){
			ans+=d;
		}
	}
	return ans;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		init();
		st=0,en=n*m+1;
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int x; 
				scanf("%d",&x);
				sum+=x;
				if((i+j)%2)
					link(st,(i-1)*m+j,x);
				else
					link((i-1)*m+j,en,x);
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if((i+j)%2){
					for(int k=0;k<4;k++){
						int x=i+d[k][0];
						int y=j+d[k][1];
						if(x<1||y<1||x>n||y>m) continue;
						int now=(i-1)*m+j,next=(x-1)*m+y;
						link(now,next,INF);
					}
				}
			}
		}
		
		int ans=dinic();
		printf("%d\n",sum-ans);
	}
	return 0;
}

