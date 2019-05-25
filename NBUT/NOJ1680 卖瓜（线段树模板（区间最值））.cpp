#include<iostream>
#define LC(a)  ((a<<1))
#define RC(a)  ((a<<1)+1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long ll;
const int N=1e4*4;

ll mmin,mmax;

struct node{
	ll l,r;
	ll mmin,mmax;	
}tree[N];

ll num[N];

void pushup(ll p)  
{  
    tree[p].mmin=min(tree[LC(p)].mmin, tree[RC(p)].mmin);
	tree[p].mmax=max(tree[LC(p)].mmax,tree[RC(p)].mmax);
}

void build(ll p,ll l,ll r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].mmax=0;
	tree[p].mmin=1e10;
	if(l==r){
		tree[p].mmax=tree[p].mmin=num[l];
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);//Õ˘…œÕ∆ 
}

void update(ll p,ll l,ll r,ll num){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){	
		tree[p].mmin=tree[p].mmax=num;
		return;
	}
	update(LC(p),l,r,num);
	update(RC(p),l,r,num);
	pushup(p);
}

void query(ll p,ll l,ll r){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		mmin=min(tree[p].mmin,mmin);
		mmax=max(tree[p].mmax,mmax);
		return;
	}
	query(LC(p),l,r);
	query(RC(p),l,r);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		build(1,1,n);
		for(int i=1;i<=q;i++){
			int p;
			cin>>p;
			if(p==1){
				ll l,r;
				cin>>l>>r;
				mmin=1e10;
				mmax=0;
				query(1,l,r);
				cout<<mmax-mmin<<endl;
			}
			else{
				ll x,idx;	
				cin>>x>>idx;
				update(1,x,x,idx);
			}
		}
	} 
}
