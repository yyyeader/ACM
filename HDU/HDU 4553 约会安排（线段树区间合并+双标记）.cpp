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
const int N=1e5+5;

struct node{
	int l,r;
	int dls,dms,drs;//屌丝 
	int nls,nms,nrs;//女神 
}tree[N<<2];

int x;

void pushup(int p){
	//屌丝
	if(tree[LC(p)].dls==tree[LC(p)].r-tree[LC(p)].l+1)
		tree[p].dls=tree[LC(p)].dls+tree[RC(p)].dls;
	else
		tree[p].dls=tree[LC(p)].dls;
	if(tree[RC(p)].drs==tree[RC(p)].r-tree[RC(p)].l+1)
		tree[p].drs=tree[RC(p)].drs+tree[LC(p)].drs;
	else
		tree[p].drs=tree[RC(p)].drs;
	tree[p].dms=max(tree[LC(p)].drs+tree[RC(p)].dls,max(tree[LC(p)].dms,tree[RC(p)].dms));
	//女神 
	if(tree[LC(p)].nls==tree[LC(p)].r-tree[LC(p)].l+1)
		tree[p].nls=tree[LC(p)].nls+tree[RC(p)].nls;
	else
		tree[p].nls=tree[LC(p)].nls;
	if(tree[RC(p)].nrs==tree[RC(p)].r-tree[RC(p)].l+1)
		tree[p].nrs=tree[RC(p)].nrs+tree[LC(p)].nrs;
	else
		tree[p].nrs=tree[RC(p)].nrs;
	tree[p].nms=max(tree[LC(p)].nrs+tree[RC(p)].nls,max(tree[LC(p)].nms,tree[RC(p)].nms));
}

void pushdown(int p){
	//屌丝 
	if(tree[p].dms==tree[p].r-tree[p].l+1){
		tree[LC(p)].dls=tree[LC(p)].dms=tree[LC(p)].drs=tree[LC(p)].r-tree[LC(p)].l+1;
		tree[RC(p)].dls=tree[RC(p)].dms=tree[RC(p)].drs=tree[RC(p)].r-tree[RC(p)].l+1;
	}
	else if(tree[p].dms==0){
		tree[LC(p)].dls=tree[LC(p)].dms=tree[LC(p)].drs=0;
		tree[RC(p)].dls=tree[RC(p)].dms=tree[RC(p)].drs=0;
	}
	//女神 
	if(tree[p].nms==tree[p].r-tree[p].l+1){
		tree[LC(p)].nls=tree[LC(p)].nms=tree[LC(p)].nrs=tree[LC(p)].r-tree[LC(p)].l+1;
		tree[RC(p)].nls=tree[RC(p)].nms=tree[RC(p)].nrs=tree[RC(p)].r-tree[RC(p)].l+1;
	}
	else if(tree[p].nms==0){
		tree[LC(p)].nls=tree[LC(p)].nms=tree[LC(p)].nrs=0;
		tree[RC(p)].nls=tree[RC(p)].nms=tree[RC(p)].nrs=0;
	}
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	if(l==r){
		tree[p].dls=tree[p].dms=tree[p].drs=tree[p].nls=tree[p].nms=tree[p].nrs=1;
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int l,int r,int op){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		if(op==1)
			tree[p].dls=tree[p].dms=tree[p].drs=0;
		else if(op==2)
			tree[p].nls=tree[p].nms=tree[p].nrs=0;
		else
			tree[p].dls=tree[p].dms=tree[p].drs=tree[p].nls=tree[p].nms=tree[p].nrs=tree[p].r-tree[p].l+1;
		return;
	}
	pushdown(p);
	update(LC(p),l,r,op);
	update(RC(p),l,r,op);
	pushup(p);
}

int query(int p,int l,int r,char op){
	//这句一定要加，否则当所需时间为1时，可能会陷入无限递归 
	if(l==r)
		return l;
	pushdown(p);
	if(op=='D'){	
		if(tree[LC(p)].dms>=x)
			return query(LC(p),l,MID(l,r),op);
		else if(tree[LC(p)].drs+tree[RC(p)].dls>=x){
			int t=tree[LC(p)].r-tree[LC(p)].drs+1;
			return t;
		}		
		else
			return query(RC(p),MID(l,r)+1,r,op);
	}
	else{
		if(tree[LC(p)].nms>=x)
			return query(LC(p),l,MID(l,r),op);
		else if(tree[LC(p)].nrs+tree[RC(p)].nls>=x){
			int t=tree[LC(p)].r-tree[LC(p)].nrs+1;
			return t;
		}		
		else
			return query(RC(p),MID(l,r)+1,r,op);
	}
	pushup(p); 
}

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n,q;
		scanf("%d%d",&n,&q);
		build(1,1,n);
		printf("Case %d:\n",++cas);
		while(q--){
			char op[10];
			scanf("%s",op);
			if(op[0]=='D'){
				scanf("%d",&x);
				if(tree[1].dms>=x){
					int l=query(1,1,n,'D');
					update(1,l,l+x-1,1);
					printf("%d,let's fly\n",l);
				}			
				else
					puts("fly with yourself");
			}
			else if(op[0]=='N'){
				scanf("%d",&x);
				int l;
				if(tree[1].dms>=x){
					l=query(1,1,n,'D'); 
					//把屌丝和女神的这段时间都安排上，因为无论对屌丝还是女神来说这段时间都被安排了。 
					update(1,l,l+x-1,1);
					update(1,l,l+x-1,2);
					printf("%d,don't put my gezi\n",l);
				}
				else if(tree[1].nms>=x){
					l=query(1,1,n,'N');
					update(1,l,l+x-1,1);
					update(1,l,l+x-1,2);
					printf("%d,don't put my gezi\n",l);
				}
				else
					puts("wait for me");	
			}
			else{
				int l,r;
				scanf("%d%d",&l,&r);
				update(1,l,r,3);
				puts("I am the hope of chinese chengxuyuan!!");
			}
		}
	}
	return 0;
}
