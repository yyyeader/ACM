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
const int N=2e2+5;

struct node{
	double x1,x2,h,flag;
}a[N];

struct node2{
	int l,r,cnt;//cnt=-1表示区间cnt不相等 
	double sum;
}tree[N<<2];

double X[N];

void pushdown(int p){
	if(tree[p].cnt<=0){
		tree[LC(p)].cnt=tree[RC(p)].cnt=0;
		tree[LC(p)].sum=tree[RC(p)].sum=0;
	}
	else{
		tree[LC(p)].cnt=tree[RC(p)].cnt=tree[p].cnt;
		tree[LC(p)].sum=X[tree[LC(p)].r+1]-X[tree[LC(p)].l];
		tree[RC(p)].sum=X[tree[RC(p)].r+1]-X[tree[RC(p)].l];
	}
}

void pushup(int p){
	tree[p].cnt=(tree[LC(p)].cnt==tree[RC(p)].cnt?tree[LC(p)].cnt:-1);
	tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].cnt=0;
	if(l==r){
		tree[p].sum=0;
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
		if(tree[p].cnt)
			tree[p].sum=X[tree[p].r+1]-X[tree[p].l];
		else
			tree[p].sum=0;
		return;
	}
	if(tree[p].cnt!=-1)
		pushdown(p);
	update(LC(p),l,r,cnt);
	update(RC(p),l,r,cnt);
	pushup(p);
}

int bin_search(double num,int l,int r){
	while(l<=r){
		int mid=(l+r)/2;
		if(num==X[mid])
			return mid;
		else if(num<X[mid])
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

bool cmp(node a,node b){
	return a.h<b.h;
}

int main(){
	int n;
	int cas=0;
	while(~scanf("%d",&n)&&n){
		printf("Test case #%d\n",++cas);
		int m1=0,m2=1;
		for(int i=1;i<=n;i++){
			double x1,x2,y1,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			X[++m1]=x1;
			a[m1].x1=x1,a[m1].x2=x2,a[m1].h=y1,a[m1].flag=1;
			X[++m1]=x2;
			a[m1].x1=x1,a[m1].x2=x2,a[m1].h=y2,a[m1].flag=-1;
		}
		sort(a+1,a+1+m1,cmp);
		//去重，离散化 
		sort(X+1,X+1+m1);
		for(int i=2;i<=m1;i++){
			if(X[i]!=X[i-1])
				X[++m2]=X[i];
		}
		
		build(1,1,m2-1);
		double ans=0;
		//这里r-1,是因为原本的l,r是端点上的，而线段树是线段所以要转化一下
		for(int i=1;i<=m1-1;i++){
			int l=bin_search(a[i].x1,1,m2);
			int r=bin_search(a[i].x2,1,m2)-1;
			update(1,l,r,a[i].flag);
			ans+=tree[1].sum*(a[i+1].h-a[i].h);
		}
		printf("Total explored area: %.2lf\n\n",ans);
	}
	return 0;
} 
