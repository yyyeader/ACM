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
const int N=5e4+5;

struct node{
	int l,r,sum;
}tree[N*4];

int ans;

void pushup(int p){
	tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	if(l==r){
		scanf("%d",&tree[p].sum);
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int t,int add){
	if(tree[p].l==tree[p].r){
		tree[p].sum+=add;
		return;
	}
	int mid=MID(tree[p].l,tree[p].r);
	if(t<=mid)
		update(LC(p),t,add);
	else
		update(RC(p),t,add);
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
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n;
		scanf("%d",&n);
		build(1,1,n);
		printf("Case %d:\n",++cas);
		char op[10];
		while(scanf("%s",op)){		
			int l,r,add,pos;	
			if(op[0]=='Q'){
				ans=0;
				scanf("%d%d",&l,&r);
				query(1,l,r);
				printf("%d\n",ans);
			}
			else if(op[0]=='A'){
				scanf("%d%d",&pos,&add);
				update(1,pos,add);
			}
			else if(op[0]=='S'){
				scanf("%d%d",&pos,&add);
				update(1,pos,-add);
			}
			else
				break;
		}
	}
	return 0;
}
