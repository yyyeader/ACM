#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
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
const int N=1e5+5;

LL ans,num;

struct node{
	int l,r;
	LL sum;
}tree[N*4];

void pushup(int p){
	tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	if(l==r){
		scanf("%lld",&tree[p].sum);
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int l,int r){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(tree[p].sum==tree[p].r-tree[p].l+1)
		return;
	if(tree[p].l==tree[p].r){
		tree[p].sum=sqrt(tree[p].sum);
		return;
	}
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
	query(LC(p),l,r);
	query(RC(p),l,r);
}

int main(){
	int n;
	int cas=0;
	while(~scanf("%d",&n)){
		build(1,1,n);
		int q;
		scanf("%d",&q);
		printf("Case #%d:\n",++cas);
		while(q--){
			int op,l,r;
			scanf("%d%d%d",&op,&l,&r);
			if(l>r)
				swap(l,r);
			if(op==0){
				update(1,l,r);
			}			
			else{
				ans=0;
				query(1,l,r);
				printf("%lld\n",ans);
			}
		}
		printf("\n");
	}
	return 0;
}
