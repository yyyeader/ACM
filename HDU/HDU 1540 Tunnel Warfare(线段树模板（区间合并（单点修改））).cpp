#include<stdio.h>
#include<algorithm>
#define LC(a) ((a<<1))
#define RC(a) ((a<<1)+1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int N=5e4+5;

struct node{
	int l,r;
	int ls,rs,ms; 
}tree[N*4];

int ans;
int last[N];
int cnt;

void pushup(int p){
	tree[p].ls=(tree[LC(p)].ls==tree[LC(p)].r-tree[LC(p)].l+1?tree[LC(p)].ls+tree[RC(p)].ls:tree[LC(p)].ls);
	tree[p].rs=(tree[RC(p)].rs==tree[RC(p)].r-tree[RC(p)].l+1?tree[RC(p)].rs+tree[LC(p)].rs:tree[RC(p)].rs);
	tree[p].ms=max(max(tree[LC(p)].ms,tree[RC(p)].ms),tree[LC(p)].rs+tree[RC(p)].ls);
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].ms=tree[p].ls=tree[p].rs=0;
	if(l==r){
		tree[p].ms=tree[p].ls=tree[p].rs=1;
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int t,int op){
	if(tree[p].l==tree[p].r){
		tree[p].ls=tree[p].rs=tree[p].ms=op;
		return;
	}
	int mid=MID(tree[p].l,tree[p].r);
	if(t<=mid)	update(LC(p),t,op);
	else	update(RC(p),t,op);
	pushup(p);
}

void query(int p,int t){
	if(tree[p].ms==0||tree[p].ms==tree[p].r-tree[p].l+1){
		ans+=tree[p].ms;
		return;
	}
	int mid=MID(tree[p].l,tree[p].r);
	if(t<=mid){
		if(t>=tree[LC(p)].r-tree[LC(p)].rs+1){
			ans+=tree[LC(p)].rs+tree[RC(p)].ls;
			return;
		}
		else
			query(LC(p),t);
	}
	else{
		if(t<=tree[RC(p)].l+tree[RC(p)].ls-1){
			ans+=tree[RC(p)].ls+tree[LC(p)].rs;
			return;
		}
		else
			query(RC(p),t);
	}
}

int main(){
	int n,q;
	while(~scanf("%d %d",&n,&q)){
		build(1,1,n);
		cnt=0;
		while(q--){
			char st[10];
			scanf("%s",st);
			int t;
			if(st[0]=='D'){
				scanf("%d",&t);
				update(1,t,0);
				last[++cnt]=t; 
			}
			else if(st[0]=='R'){
				if(cnt!=0){
					t=last[cnt--];
					update(1,t,1);
				}
			}
			else{
				ans=0;
				scanf("%d",&t);
				query(1,t);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
