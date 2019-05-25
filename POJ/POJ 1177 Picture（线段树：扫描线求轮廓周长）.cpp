#include<cstdio>
#include<cmath>
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
const int N=1e4+5;

struct Node{
	int l,r,cnt,sum;//sum为测度 
}tree[N*2*4]; 

struct node{
	int l,r,h,flag;
	node(){}
	node(double a,double b,double c,double d){
		l=a;r=b;h=c;flag=d;
	}
}a[N],b[N];

bool cmp(node a,node b){
	return a.h<b.h;
}

void pushup(int p) {
	if(tree[p].cnt>0)
		tree[p].sum=tree[p].r-tree[p].l+1;
	else if(tree[p].l==tree[p].r)
		tree[p].sum=0;
	else
		tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	if(l==r){
		tree[p].cnt=tree[p].sum=0;
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int l,int r,int cnt){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(l<=tree[p].l&&r>=tree[p].r&&tree[p].cnt!=-1){
		tree[p].cnt+=cnt;
		pushup(p);
		return;
	}
	update(LC(p),l,r,cnt);
	update(RC(p),l,r,cnt);
	pushup(p);
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		int m1=0,m2=1;
		for(int i=1;i<=n;i++){
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1+=N,x2+=N,y1+=N,y2+=N;//防止x,y出现负数 
			a[++m1]=node(x1,x2,y1,1);
			b[m1]=node(y1,y2,x1,1);
			a[++m1]=node(x1,x2,y2,-1);
			b[m1]=node(y1,y2,x2,-1);
		}
		sort(a+1,a+1+m1,cmp);
		sort(b+1,b+1+m1,cmp);
		//自下往上扫描一遍 
		build(1,1,2*N-1);
		int ans=0;
		for(int i=1;i<=m1;i++){
			int last=tree[1].sum;
			int l=a[i].l;
			int r=a[i].r-1;
			update(1,l,r,a[i].flag);
			ans+=abs(tree[1].sum-last);
		}
		//自左往右扫描一遍
		build(1,1,2*N-1);
		for(int i=1;i<=m1;i++){
			int last=tree[1].sum;
			int l=b[i].l;
			int r=b[i].r-1;
			update(1,l,r,b[i].flag);
			ans+=abs(tree[1].sum-last);
		}
		printf("%d\n",ans);	
	}
	return 0;
}
