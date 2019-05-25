#include<iostream>
#include<cstring>
#include<algorithm>
#define LC(a) ((a<<1))
#define RC(a) ((a<<1)+1)
#define MID(a,b) ((a+b)>>1) 
using namespace std; 
typedef long long ll;
const int N=5e4*4;

struct node{
	ll l,r;
	ll color;//颜色为-1表示混合色 
}tree[N];

struct knode{
	ll l,r;//用来存储题目给定的区间 
}tmp[N];

ll ans[N];//记录颜色i是否存在 
ll Hash[N];//存储坐标映射 
ll point[N];//存储坐标序列  
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
	tree[p].color=0;
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

//二分查找 
ll Bin_search(ll l,ll r,ll x){
	ll mid;
	while(l<=r){
		mid=(l+r)/2;
		if(x==Hash[mid])	return mid;
		if(x<Hash[mid]) 	r=mid-1;
		else if(x>Hash[mid])	l=mid+1;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;	 
		//***对输入数据进行离散化
		ll m1=0;
		
		for(int i=1;i<=n;i++){
			ll l,r;
			cin>>tmp[i].l>>tmp[i].r;
			point[++m1]=tmp[i].l;
			point[++m1]=tmp[i].r;
		}
		sort(point+1,point+1+m1);
		ll m2=0;
		for(int i=1;i<=m1;i++){
			if(point[i]!=point[i-1]){
				if(point[i]-point[i-1]>1&&i!=1){	
					Hash[++m2]=(point[i]+point[i-1])>>1;
					Hash[++m2]=point[i];
				}
				else
					Hash[++m2]=point[i];
			}
		}
		//**建树 
		build(1,1,m2);
		for(int i=1;i<=n;i++){
			ll l=Bin_search(1,m2,tmp[i].l);
			ll r=Bin_search(1,m2,tmp[i].r);
			update(1,l,r,i);
		}
		memset(ans,0,sizeof(ans));
		query(1,1,m2);
		ll cnt=0;
		for(int i=1;i<=m2;i++){
			if(ans[i]){
				cnt++;
			}		
		} 
		cout<<cnt<<endl;
	}
}

