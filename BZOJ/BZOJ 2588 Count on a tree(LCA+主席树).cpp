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
const int INF=0x3f3f3f3f;

int n,m,cnt;
int dep[N],val[N],rt[N],fa[N][31]; 
struct node{int l,r,sum;}tree[N*40];
vector<int>v[N];
vector<int>ve;

int getid(int x){
	return lower_bound(ve.begin(),ve.end(),x) -ve.begin()+1;
}

void init(){
	cnt=0;
	ve.clear();
	rep(i,0,n) v[i].clear();
	memset(rt,0,sizeof(rt));
	memset(dep,0,sizeof(dep));
	memset(fa,-1,sizeof(fa));
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int dc=dep[x]-dep[y];
	rep(i,0,30)
		if(dc&1<<i) x=fa[x][i];
	if(x==y) return x;
	per(i,30,0)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

void update(int l,int r,int pre,int &cur,int pos){
	tree[++cnt]=tree[pre];tree[cnt].sum++;cur=cnt;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(mid>=pos)
		update(l,mid,tree[pre].l,tree[cur].l,pos);
	else
		update(mid+1,r,tree[pre].r,tree[cur].r,pos);
}

int query(int l,int r,int x,int y,int z,int w,int k){
	if(l==r) return l;
	int mid=(l+r)>>1;
	int sum=tree[tree[x].l].sum+tree[tree[y].l].sum-tree[tree[z].l].sum-tree[tree[w].l].sum;
	if(sum>=k)
		return query(l,mid,tree[x].l,tree[y].l,tree[z].l,tree[w].l,k);
	else
		return query(mid+1,r,tree[x].r,tree[y].r,tree[z].r,tree[w].r,k-sum);
}

void dfs(int u){
	update(1,n,rt[fa[u][0]],rt[u],getid(val[u]));
	rep(i,1,30)
	    if((1<<i)<=dep[u]) fa[u][i]=fa[fa[u][i-1]][i-1];
	    else break;
	rep(i,0,(int)v[u].size()-1){
		int t=v[u][i];
		if(t==fa[u][0]) continue;
		fa[t][0]=u;
		dep[t]=dep[u]+1;
		dfs(t);
	}
}

int main(){
	FAST_IO;
	cin>>n>>m;
	init();
	rep(i,1,n) cin>>val[i],ve.push_back(val[i]);
	sort(ve.begin(),ve.end());
	ve.erase(unique(ve.begin(),ve.end()),ve.end());
	rep(i,1,n-1){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	int last=0;
	rep(i,1,m){
		int u,v,k;
		cin>>u>>v>>k;
		u=u^last;
		int LCA=lca(u,v);
		last=ve[query(1,n,rt[u],rt[v],rt[LCA],rt[fa[LCA][0]],k)-1];
		cout<<last<<(i==m?"":"\n");
	}
	return 0;
}
