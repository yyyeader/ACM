#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=5e4+5;

int ans,x,Start,End,flag;

struct node{
	int sum,l,r;//sum表示空花瓶数 
}tree[4*N];

void pushdown(int p){
	//全满 
	if(tree[p].sum==tree[p].r-tree[p].l+1){
		tree[LC(p)].sum=tree[LC(p)].r-tree[LC(p)].l+1;
		tree[RC(p)].sum=tree[RC(p)].r-tree[RC(p)].l+1;
	}
	//全空 
	else if(tree[p].sum==0)
		tree[LC(p)].sum=tree[RC(p)].sum=0;
}

void pushup(int p){
	tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	if(l==r){
		tree[p].sum=1;
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int l,int r){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(x<=0)
		return;	
	if(l<=tree[p].l&&r>=tree[p].r){
		if(tree[p].sum==0)
			return;
		//找到全空区间 
		if(x>=tree[p].sum&&tree[p].sum==tree[p].r-tree[p].l+1){
			if(flag==0){
				Start=tree[p].l;
				flag++;
			}
			x-=tree[p].sum;
			tree[p].sum=0;	
			End=tree[p].r;
			return;
		}
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
		ans+=tree[p].r-tree[p].l+1-tree[p].sum;
		tree[p].sum=tree[p].r-tree[p].l+1;
		return;
	}
	pushdown(p);
	query(LC(p),l,r);
	query(RC(p),l,r);
	pushup(p);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,q;
		scanf("%d%d",&n,&q);
		build(1,0,n-1);
		while(q--){
			int op;
			scanf("%d",&op);
			if(op==1){
				int l;
				scanf("%d%d",&l,&x);
				flag=0;
				update(1,l,n-1);
				if(flag==0)
					printf("Can not put any one.\n");
				else
					printf("%d %d\n",Start,End);
			}
			else{
				int l,r;
				scanf("%d%d",&l,&r);
				ans=0;
				query(1,l,r);
				printf("%d\n",ans);
			} 
		}
		printf("\n");
	}
	return 0;
}
