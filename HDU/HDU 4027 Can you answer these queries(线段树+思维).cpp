/*一个数大概5、6次开根号后就变成1了，所以直接记录该区间是否都为1即可*/ 
#include<iostream>
#include<algorithm>
#include<math.h>
#define LC(a) ((a<<1))
#define RC(a) ((a<<1)+1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long ll;
const int N=1e5*4;

struct node{
	ll l,r;
	ll sum;
	bool sign;//是否这块区间里的数都为1 
}tree[N]; 

ll ans;

void pushup(ll p){
	tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
	if(tree[LC(p)].sum==(tree[LC(p)].r-tree[LC(p)].l+1)&&tree[RC(p)].sum==(tree[RC(p)].r-tree[RC(p)].l+1)){
		tree[p].sign=true;
	}
	else
		tree[p].sign=false;
}

void build(ll p,ll l,ll r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].sign=false;
	if(l==r){
		cin>>tree[p].sum;
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(ll p,ll l,ll r){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(tree[p].sign){
		return;
	}
	if(tree[p].l==tree[p].r){
		tree[p].sum=sqrt(tree[p].sum);
		return;
	}
	update(LC(p),l,r);
	update(RC(p),l,r);
	pushup(p);
}

void query(ll p,ll l,ll r){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		ans+=tree[p].sum;
		return;
	}
	query(LC(p),l,r);
	query(RC(p),l,r);
}

int main(){
	ios::sync_with_stdio(false);
	ll n;
	ll cas=0;
	while(cin>>n){
		cas++;	
		build(1,1,n);		
		ll m;
		cin>>m;
		cout<<"Case #"<<cas<<":"<<endl;
		while(m--){
			ll p,l,r;
			cin>>p>>l>>r;
			if(l>r) swap(l,r);
			if(p==0){
				update(1,l,r);
			}
			else{
				ans=0;
				query(1,l,r);
				cout<<ans<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
