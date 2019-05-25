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
const int N=1e5+5;
const LL INF=1e18;

struct node{int l,r,size;LL sum;}tree[N*40];
struct qnode{int p,w;};
int n,m,cnt,idx;
int head[N],root[N];
vector<int>ve;
vector<qnode>v[N];

int getid(int x){
	return lower_bound(ve.begin(),ve.end(),x)-ve.begin()+1;
}

void insert(int l,int r,int pre,int &cur,int pos,int w){
	tree[++cnt]=tree[pre];tree[cnt].size+=w;tree[cnt].sum+=w*ve[pos-1];cur=cnt;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(pos<=mid) insert(l,mid,tree[pre].l,tree[cur].l,pos,w);
	else insert(mid+1,r,tree[pre].r,tree[cur].r,pos,w);
}

LL query(int l,int r,int x,int k){
	if(l==r) return ve[l-1]*k;
	int mid=(l+r)>>1;
	if(k<=tree[tree[x].l].size) return query(l,mid,tree[x].l,k);
	else return tree[tree[x].l].sum+query(mid+1,r,tree[x].r,k-tree[tree[x].l].size);
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int s,e,p;
		scanf("%d%d%d",&s,&e,&p);
		v[s].push_back({p,1});
		v[e+1].push_back({p,-1});
		ve.push_back(p);
	}
	sort(ve.begin(),ve.end());
	ve.erase(unique(ve.begin(),ve.end()),ve.end());
	rep(i,1,n){
		root[i]=root[i-1];
		rep(j,0,(int)v[i].size()-1){
			qnode t=v[i][j];
			insert(1,ve.size(),root[i],root[i],getid(t.p),t.w);
		}
	}
	LL pre=1;
	rep(i,1,m){
		LL x,a,b,c,k;
		scanf("%lld%lld%lld%lld",&x,&a,&b,&c);
		k=1+(a*pre+b)%c;
		if(k>=tree[root[x]].size)
			pre=tree[root[x]].sum;
		else
			pre=query(1,ve.size(),root[x],k);
		printf("%lld\n",pre);
	}
	return 0;
}

