#include<cstring>
#include<stdio.h>
#define LC(a) ((a<<1))
#define RC(a) ((a<<1)+1)
#define MID(a,b) ((a+b)>>1) 
typedef long long ll;
const int N=1e5*4;

struct node{
	ll l,r;
	ll color;//颜色为-1表示混合色 
}tree[N];

ll ans[35]; 
//下推 
void pushdown(ll p){
	tree[RC(p)].color=tree[LC(p)].color=tree[p].color;
}
//上推 
void pushup(ll p){
	tree[p].color=(tree[LC(p)].color==tree[RC(p)].color?tree[LC(p)].color:-1);
}

void build(ll p,ll l,ll r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].color=1;//初始化颜色因题意而定 
	if(l==r){
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
}

void update(ll p,ll l,ll r,ll color){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		tree[p].color=color;		
		return;
	}
	//**释放lazy标记 
	if(tree[p].color!=-1){
		pushdown(p);
	}
	update(LC(p),l,r,color);
	update(RC(p),l,r,color);
	pushup(p);
}

void query(ll p,ll l,ll r){
	if(r<tree[p].l||l>tree[p].r)
		return;
	//纯色，不用再找下去 
	if(tree[p].color!=-1){
		ans[tree[p].color]=1;
		return;
	}		
	query(LC(p),l,r);
	query(RC(p),l,r);
}

int main(){
	ll L,t,o;
	scanf("%I64d %I64d %I64d",&L,&t,&o);
	build(1,1,L);
	while(o--){
		char p[15];
		scanf("%s",p);
		if(p[0]=='C'){
			ll l,r,color;
			scanf("%I64d %I64d %I64d",&l,&r,&color);
			if(l>r)//l可能大于r 
				update(1,r,l,color);
			else
				update(1,l,r,color);
		}
		else{
			ll l,r;
			scanf("%I64d %I64d",&l,&r);
			memset(ans,0,sizeof(ans));
			if(l>r)
				query(1,r,l);
			else
				query(1,l,r);	
			ll sum=0;
			for(int i=1;i<=t;i++){
				if(ans[i])
					sum++;
			}
			printf("%I64d\n",sum);
		}
	}
}
