#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{int l,r,fa,deep;}tree[N*40];
int cnt,n,m;
int rt[N];

void build(int l,int r,int &cur){
	cur=++cnt;
	if(l==r){
		tree[cnt].fa=l;
		tree[cnt].deep=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,tree[cur].l);
	build(mid+1,r,tree[cur].r);
}
//将pos的父亲修改为fa 
void update(int l,int r,int pre,int &cur,int pos,int fa){
	tree[++cnt]=tree[pre];cur=cnt;
	if(l==r){
		tree[cnt].fa=fa;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,tree[pre].l,tree[cur].l,pos,fa);
	else update(mid+1,r,tree[pre].r,tree[cur].r,pos,fa);
}

//修改pos的深度 
void add(int l,int r,int cur,int pos){
	if(l==r){
		tree[cur].deep++;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) add(l,mid,tree[cur].l,pos);
	else add(mid+1,r,tree[cur].r,pos);
}

//询问在当前状态下,pos对应的节点编号 
int query(int l,int r,int cur,int pos){
	if(l==r)
		return cur;
	int mid=(l+r)>>1;
	if(pos<=mid)  return query(l,mid,tree[cur].l,pos);
	else return query(mid+1,r,tree[cur].r,pos);
}

//查询在rt状态下,x的父亲所在的节点编号 
int find(int rt,int x){
	int p=query(1,n,rt,x);
	if(tree[p].fa==x) return p;
	return find(rt,tree[p].fa);
}

int main(){
	scanf("%d%d",&n,&m);
	build(1,n,rt[0]);
	int ans=0;
	rep(i,1,m){
		int op,a,b,k;
		scanf("%d",&op);
		rt[i]=rt[i-1];
		if(op==1){
			scanf("%d%d",&a,&b);
			a^=ans,b^=ans;
			int t1=find(rt[i],a),t2=find(rt[i],b);
			if(t1==t2) continue;
			if(tree[t1].deep>tree[t2].deep) swap(t1,t2);
			update(1,n,rt[i-1],rt[i],tree[t1].fa,tree[t2].fa);
			if(tree[t1].deep==tree[t2].deep) add(1,n,rt[i],tree[t2].fa);
		}
		if(op==2){
			scanf("%d",&k);
			rt[i]=rt[k];
		}
		if(op==3){
			scanf("%d%d",&a,&b);
			int t1=find(rt[i],a),t2=find(rt[i],b);
			if(t1==t2) ans=1;
			else ans=0;
			printf("%d\n",ans);
		}
	}
	return 0;
}

