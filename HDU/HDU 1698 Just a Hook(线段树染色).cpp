#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
using namespace std; 
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=1e5+5;

struct node{
	int l,r,col;
}tree[N*4];

LL ans;

void pushdown(int p){
	tree[LC(p)].col=tree[RC(p)].col=tree[p].col;
}

void pushup(int p){	
	tree[p].col=(tree[LC(p)].col==tree[RC(p)].col?tree[LC(p)].col:-1);
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	if(l==r){
		tree[p].col=1;
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int l,int r,int col){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		tree[p].col=col;
		return;
	}
	if(tree[p].col!=-1)
		pushdown(p);
	update(LC(p),l,r,col);
	update(RC(p),l,r,col);
	pushup(p);
}

void query(int p,int l,int r){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(l<=tree[p].l&&r>=tree[p].r&&tree[p].col!=-1){
		ans+=tree[p].col*(tree[p].r-tree[p].l+1);
		return;
	}
	if(tree[p].col!=-1)
		pushdown(p);
	query(LC(p),l,r);
	query(RC(p),l,r);
	pushup(p);
}

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		build(1,1,n);
		while(m--){
			int l,r,col;
			scanf("%d%d%d",&l,&r,&col);
			update(1,l,r,col);
		}
		ans=0;
		query(1,1,n);
		printf("Case %d: The total value of the hook is %d.\n",++cas,ans);
	}
	return 0;
}
