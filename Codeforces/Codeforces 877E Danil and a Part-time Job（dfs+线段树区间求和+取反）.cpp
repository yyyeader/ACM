#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=2e5+5;

int cnt,ans;
int Start[N],End[N],col[N],tmp[N];
vector<int>v[N];

struct node{
	int l,r,sum,add;
}tree[N*4];

void pushup(int p){
	tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
}

void pushdown(int p){
	if(tree[p].add){
		tree[LC(p)].add=(tree[LC(p)].add+tree[p].add)%2;
		tree[RC(p)].add=(tree[RC(p)].add+tree[p].add)%2;
		tree[LC(p)].sum=tree[LC(p)].r-tree[LC(p)].l+1-tree[LC(p)].sum;
		tree[RC(p)].sum=tree[RC(p)].r-tree[RC(p)].l+1-tree[RC(p)].sum;
		tree[p].add=0;
	}
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].add=0;
	if(l==r){
		tree[p].sum=col[l];
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int l,int r){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		tree[p].sum=tree[p].r-tree[p].l+1-tree[p].sum;
		tree[p].add=(tree[p].add+1)%2;
		return;
	}
	pushdown(p);
	update(LC(p),l,r);
	update(RC(p),l,r);
	pushup(p);
}

void query(int p,int l,int r){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		ans+=tree[p].sum;
		return;
	}
	pushdown(p);
	query(LC(p),l,r);
	query(RC(p),l,r);
	pushup(p);
}

void dfs(int x){
	Start[x]=++cnt;
	col[cnt]=tmp[x];
	for(int i=0;i<v[x].size();i++){
		int t=v[x][i];
		dfs(t);
	}
	End[x]=cnt;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int pi;
		scanf("%d",&pi);
		v[pi].push_back(i+1);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp[i]);
	}
	dfs(1);
	build(1,1,n);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		char op[10];
		scanf("%s",op);
		int x;
		if(op[0]=='g'){
			scanf("%d",&x);
			ans=0;
			query(1,Start[x],End[x]);
			printf("%d\n",ans);
		}
		else if(op[0]=='p'){
			scanf("%d",&x);
			update(1,Start[x],End[x]);
		}
	}
	return 0;
}
