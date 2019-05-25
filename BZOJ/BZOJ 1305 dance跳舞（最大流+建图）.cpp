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
const int N=5e2+5;
const int M=5e3+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
}edge[M*2];

int cnt,st,en,n,k;
int head[N],dep[N],like[N][N];

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
	if(u==en) return fl;
	for(int i=head[u];i;i=edge[i].next){
		node &t=edge[i];
		if(t.flow&&dep[u]+1==dep[t.to]){
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
		while(int d=dfs(st,INF)){
			ans+=d;
		}
	}
	return ans;
}

void build(int mid){
	init(); 
	for(int i=1;i<=n;i++){
		link(st,i,mid);
		link(i,i+n,k);
		link(i+2*n,en,mid);
		link(i+3*n,i+2*n,k);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(like[i][j])
				link(i,j+2*n,1);
			else
				link(i+n,j+3*n,1);
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<=n;i++){
			char tmp[100];
			scanf("%s",tmp+1);
			for(int j=1;j<=n;j++){
				if(tmp[j]=='Y')
					like[i][j]=1;
			}
		}
		st=0,en=4*n+1;
		int l=0,r=n,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			build(mid);
			int sum=dinic();
			if(sum>=n*mid){
				ans=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

