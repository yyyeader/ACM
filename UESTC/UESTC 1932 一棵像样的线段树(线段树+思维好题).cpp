#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define MID(a,b) ((a+b)>>1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int l,r,mmin;
}tree[N<<2];

int ans;
int c[N];

void pushup(int p){
	tree[p].mmin=min(tree[lc(p)].mmin,tree[rc(p)].mmin);
}

void build(int p,int l,int r){
	tree[p]=node{l,r,-1};
	if(l==r){
		if(l==1)
			tree[p].mmin=0;
		return;
	}
	int mid=MID(l,r);
	build(lc(p),l,mid);
	build(rc(p),mid+1,r);
	pushup(p);
}

void update(int p,int pos,int t){
	if(tree[p].l==tree[p].r){
		tree[p].mmin=t;
		return;
	}
	int mid=MID(tree[p].l,tree[p].r);
	if(pos<=mid)
		update(lc(p),pos,t);
	else
		update(rc(p),pos,t);
	pushup(p);
}

void query(int p,int v){
	if(tree[p].l==tree[p].r){
		ans=tree[p].l;
		return;
	}
	if(v<=tree[lc(p)].mmin)
		query(rc(p),v);
	else
		query(lc(p),v);
}

int main(){
	int n;
	scanf("%d",&n);
	build(1,1,n+1);
	query(1,0);
	rep(i,1,n){
		scanf("%d",&c[i]);
		int v=i-c[i];
		query(1,v);//ÕÒµ½min{x} (last[x]<i-c[i])
		printf("%d ",ans);
		update(1,ans,i);
	}
	puts("");
	return 0;
}

