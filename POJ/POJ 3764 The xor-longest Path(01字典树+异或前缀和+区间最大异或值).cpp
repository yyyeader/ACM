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
using namespace std;
const int N=2e5+5;
const int M=4e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next;
	int w;
}edge[N];

int idx,cnt;
int head[N],sum[N],id[M];
int trie[M][2];

int newnode(){
	for(int i=0;i<2;i++)
		trie[idx][i]=-1;
	return idx++;
}

void init(){
	cnt=1;
	idx=0;
	newnode();
	memset(head,0,sizeof(head));
}

void add(int u,int v,int w){
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].w=w;
	head[u]=cnt++;
}

void dfs(int u,int fa){
	for(int i=head[u];i;i=edge[i].next){
		node t=edge[i];
		if(t.to==fa) continue;
		sum[t.to]=sum[u]^t.w;
		dfs(t.to,u);
	}
}

void insert(int x){
	int now=0;
	for(int i=31;i>=0;i--){
		int tmp=x&(1<<i);
		if(tmp>0) tmp=1;
		if(trie[now][tmp]==-1)
			trie[now][tmp]=newnode();
		now=trie[now][tmp];
	}
	id[now]=x;
}

int query(int x){
	int now=0;
	for(int i=31;i>=0;i--){
		int tmp=x&(1<<i);
		if(tmp>0) tmp=1;
		if(trie[now][tmp^1]!=-1)
			now=trie[now][tmp^1];
		else
			now=trie[now][tmp];
	}
	return x^id[now];
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		init();
		for(int i=1;i<n;i++){
			int u,v;
			int w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		dfs(0,-1);
		int ans=-1;
		for(int i=0;i<n;i++){
			ans=max(ans,query(sum[i]));
			insert(sum[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

