/*
此题需要对奶牛进行拆点，左边食物（水），中间奶牛1，奶牛2，右边水（食物） 
拆点是为了限制奶牛只能吃一份食物和谁，若不对奶牛进行拆点，则一头奶牛可能会吃多份食物和水 
*/
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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
}edge[M*2];

int cnt,st,en;
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
	int n,f,d;
	while(~scanf("%d%d%d",&n,&f,&d)){
		init();
		st=0,en=f+2*n+d+1;
		for(int i=1;i<=n;i++){
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			for(int j=1;j<=t1;j++){
				int x;
				scanf("%d",&x);
				link(x,i+f,1);
			}
			for(int j=1;j<=t2;j++){
				int x;
				scanf("%d",&x);
				link(i+f+n,x+f+2*n,1);
			}
		}
		for(int i=1;i<=f;i++) link(st,i,1);
		for(int i=1;i<=n;i++) link(i+f,i+f+n,1);
		for(int i=1;i<=d;i++) link(i+f+2*n,en,1);
		printf("%d\n",dinic());
	}
	return 0;
}

