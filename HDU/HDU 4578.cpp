#include<iostream>
#include<stdio.h> 
#define ADD 1
#define MUL 2
#define COL 3
#define LC(a) ((a<<1))
#define RC(a) ((a<<1)+1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long ll;
const int N=1e5+5;
const ll MOD=10007;

struct node{
	ll l,r;
	ll sum,add,mul,color; 
}tree[N<<2];

ll ans; 
//还有取余的问题
void pushup(ll p){
	tree[p].sum=(tree[LC(p)].sum+tree[RC(p)].sum)%MOD;
	if(tree[LC(p)].color==tree[RC(p)].color){
		if(tree[LC(p)].sum==tree[LC(p)].color*(tree[LC(p)].r-tree[LC(p)].l+1)&&tree[RC(p)].sum==tree[RC(p)].color*(tree[RC(p)].r-tree[RC(p)].l+1)){
			tree[p].color=tree[LC(p)].color; 
		}	
	} 
	else{
		tree[p].color=-2;
	}
}


ll power(ll x,ll num){
	ll sum=1;
	for(int i=1;i<=num;i++){
		sum*=x;
	}
	return sum;
}

void pushdown(ll p){
	//要清空add,mul 
	if(tree[p].color!=-2&&tree[p].color!=-1){	
		tree[LC(p)].mul=tree[LC(p)].add=tree[RC(p)].mul=tree[RC(p)].add=0;
		tree[LC(p)].color=tree[RC(p)].color=tree[p].color;
		tree[LC(p)].sum=(tree[LC(p)].color*(tree[LC(p)].r-tree[LC(p)].l+1))%MOD;
		tree[RC(p)].sum=(tree[RC(p)].color*(tree[RC(p)].r-tree[RC(p)].l+1))%MOD;		
	}
	else{
		//***这里只乘最初的sum,不然都算在add里 
		tree[LC(p)].add=(tree[LC(p)].add*tree[p].mul)%MOD;
		tree[RC(p)].add=(tree[RC(p)].add*tree[p].mul)%MOD;
		tree[LC(p)].add=(tree[LC(p)].add+tree[p].add)%MOD;
		tree[RC(p)].add=(tree[RC(p)].add+tree[p].add)%MOD;
		tree[LC(p)].mul=(tree[LC(p)].mul+tree[p].mul)%MOD;
		tree[RC(p)].mul=(tree[RC(p)].mul+tree[p].mul)%MOD;
		tree[LC(p)].sum=(tree[p].mul*tree[LC(p)].sum+tree[p].add*(tree[LC(p)].r-tree[RC(p)].l+1))%MOD;
		tree[p].add=tree[p].sum=0; 
	} 
}

void build(ll p,ll l,ll r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].mul=tree[p].add=tree[p].sum=0;
	tree[p].color=-1;
	if(l==r){
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}
//解决cover的问题 
void update(ll p,ll l,ll r,ll sign,ll x){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		if(sign==MUL){
			tree[p].mul+=x;
			tree[p].add*=x;
			tree[p].sum=x*(tree[p].r-tree[p].l+1)%MOD;
		}
		else if(sign==ADD){
			tree[p].add+=x;
			tree[p].sum=(tree[p].sum+x*(tree[p].r-tree[p].l+1))%MOD;
		}
		else{
			tree[p].mul=tree[p].add=0;
			tree[p].color=x;
			tree[p].sum=tree[p].color*(tree[p].r-tree[p].l+1);
		}
		return;
	}
	pushdown(p);
	update(LC(p),l,r,sign,x);
	update(RC(p),l,r,sign,x);
	pushup(p);
}

void query(ll p,ll l,ll r,ll x){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		//****还没写好 
		return;
	}
	pushdown(p)	;
	query(LC(p),l,r,x);
	query(RC(p),l,r,x);
	pushup(p);
}

int main(){
	ll n,m;
	while(scanf("%I64d %I64d",&n,&m)&&(m||n)){
		build(1,1,n);
		for(int i=1;i<=m;i++){
			ll op,l,r,x;
			scanf("%I64d %I64d %I64d %I64d",&op,&l,&r,&x);
			if(op==ADD){
				update(1,l,r,ADD,x);
			}
			else if(op==MUL){
				update(1,l,r,MUL,x);
			}
			else if(op==COL){
				update(1,l,r,COL,x);
			}
			else{
				ans=0;
				query(1,l,r,x);
				printf("%I64d\n",ans);
			}
		}
	}
	return 0;
}
 
