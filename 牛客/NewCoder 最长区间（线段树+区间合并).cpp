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
#define lc(p) (p<<1)
#define rc(p) (p<<1|1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{int l,r,ls,rs,ms,ln,rn;}tree[N*4];
int a[N];

void pushup(int p){
	node &rt=tree[p],&lc=tree[lc(p)],&rc=tree[rc(p)];
	rt.ln=lc.ln,rt.rn=rc.rn;
	rt.ls=lc.ls,rt.rs=rc.rs;
	rt.ms=max(lc.ms,rc.ms);
	if(lc.rn<rc.ln){
		rt.ms=max(rt.ms,lc.rs+rc.ls);
		if(lc.ls==lc.r-lc.l+1)
			rt.ls=lc.ls+rc.ls;
		if(rc.rs==rc.r-rc.l+1)
			rt.rs=rc.rs+lc.rs;
	}
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	if(l==r){
		tree[p].ls=tree[p].rs=tree[p].ms=1;
		tree[p].ln=tree[p].rn=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lc(p),l,mid);
	build(rc(p),mid+1,r);
	pushup(p);
}

void update(int p,int pos,int val){
	if(tree[p].l==tree[p].r){
		tree[p].ln=tree[p].rn=val;
		return;
	}
	int mid=(tree[p].l+tree[p].r)>>1;
	if(pos<=mid)
		update(lc(p),pos,val);
	else
		update(rc(p),pos,val);
	pushup(p);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	printf("%d\n",tree[1].ms);
	rep(i,1,m){
		int pos,val;
		scanf("%d%d",&pos,&val);
		update(1,pos,val);
		printf("%d\n",tree[1].ms);
	}
	return 0;
}

