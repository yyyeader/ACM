#include<iostream>
#define LC(a) ((a<<1))
#define RC(a) ((a<<1)+1)
#define MID(a,b)   ((a+b)>>1)
using namespace std;
typedef long long ll;
const int N=5e5*4;

struct node{
	ll l,r;
	ll sum;
}tree[N];

ll ans=0;

void pushup(ll p){
	tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
}

void build(ll p,ll l,ll r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].sum=0;
	if(l==r){
		cin>>tree[p].sum;
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void updata(ll p,ll l,ll r,ll num){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		tree[p].sum+=num;
		return;
	}
	updata(LC(p),l,r,num);
	updata(RC(p),l,r,num);
	pushup(p);
} 

void query(ll p,ll l, ll r){
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
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		build(1,1,n);
		
		char s[10];
		cout<<"Case "<<i<<":"<<endl;
		while(cin>>s&&s[0]!='E'){
			if(s[0]=='A'){
				ll m,k;
				cin>>m>>k;
				updata(1,m,m,k);
			}
			else if(s[0]=='S'){
				ll m,k;
				cin>>m>>k;
				updata(1,m,m,-k);
			}
			else{
				ll l,r;
				cin>>l>>r;
				ans=0;
				query(1,l,r);
				cout<<ans<<endl; 
			}
		}
	}	
}

