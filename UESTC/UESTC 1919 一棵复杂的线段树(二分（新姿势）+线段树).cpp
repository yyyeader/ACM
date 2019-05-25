#include<iostream>
#include<cstdio>
#include<cstring>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define MID(a,b) ((a+b)>>1)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define N 2000005
using namespace std;

struct node{
	int l,r,sum,lazy;
}tree[N*4];

struct qnode{
	int op,l,r;
}q[N];

int mid,ans;
int a[N];

void pushup(int p){
	tree[p].sum=tree[lc(p)].sum+tree[rc(p)].sum;
	if(tree[lc(p)].lazy==tree[rc(p)].lazy)
		tree[p].lazy=tree[lc(p)].lazy;
	else
		tree[p].lazy=-1;
}

void pushdown(int p){
	node &rt=tree[p],&lc=tree[lc(p)],&rc=tree[rc(p)];
	lc.sum=rt.lazy*(lc.r-lc.l+1);
	rc.sum=rt.lazy*(rc.r-rc.l+1);
	lc.lazy=rc.lazy=rt.lazy;
}

void build(int p,int l,int r){
	tree[p]=node{l,r,0,-1};
	if(l==r){
		tree[p].lazy=-1;
		if(a[l]>=mid)
			tree[p].sum=1;
		else
			tree[p].sum=0;
		return;
	}
	build(lc(p),l,MID(l,r));
	build(rc(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int l,int r,int add){
	if(tree[p].r<l||tree[p].l>r) return;
	if(tree[p].lazy==add) return;
	if(l<=tree[p].l&&tree[p].r<=r){
		tree[p].lazy=add;
		tree[p].sum=add*(tree[p].r-tree[p].l+1);
		return;
	}
	if(tree[p].lazy!=-1)
		pushdown(p);
	update(lc(p),l,r,add);
	update(rc(p),l,r,add);
	pushup(p);
}

void query(int p,int l,int r){
	if(tree[p].r<l||tree[p].l>r) return;
	if(l<=tree[p].l&&tree[p].r<=r){
		ans+=tree[p].sum;
		return;
	}
	if(tree[p].lazy!=-1)
		pushdown(p);
	query(lc(p),l,r);
	query(rc(p),l,r);
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	rep(i,1,m) scanf("%d%d%d",&q[i].op,&q[i].l,&q[i].r);
	int l=1,r=n;
	//二分新姿势
	while(l<=r){
		if(l==r){
			printf("%d\n",l);
			return 0;
		}
		mid=(l+r)/2;
		mid++;
		build(1,1,n);
		mid--;
		rep(i,1,m){
			ans=0;
			query(1,q[i].l,q[i].r);
			update(1,q[i].l,q[i].r,0);
			if(q[i].op)
				update(1,q[i].l,q[i].l+ans-1,1);
			else
				update(1,q[i].r-ans+1,q[i].r,1);
		}
		ans=0;
		query(1,k,k);
		if(ans)
			l=mid+1;
		else
			r=mid;
	}
	return 0;
}
