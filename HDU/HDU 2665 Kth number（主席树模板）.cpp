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
const int N=1e5+6;
const int INF=0x3f3f3f3f;

struct node{int l,r,sum;}tree[N*40];//一般开40倍即可 
vector<int>v;
int cnt;
int a[N],rt[N];

void init(){
	cnt=0;
	v.clear();
	memset(rt,0,sizeof(rt));
}

int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

//在pos插入一个数 
void update(int pre,int &cur,int l,int r,int pos){
	tree[++cnt]=tree[pre];tree[cnt].sum++;cur=cnt;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(mid>=pos) 
		update(tree[pre].l,tree[cur].l,l,mid,pos);
	else 
		update(tree[pre].r,tree[cur].r,mid+1,r,pos);
}

//查询区间[x,y]的第k小 
int query(int x,int y,int l,int r,int k){
	if(l==r) return l;
	int mid=(l+r)>>1;
	int sum=tree[tree[y].l].sum-tree[tree[x].l].sum;
	if(sum>=k)
		return query(tree[x].l,tree[y].l,l,mid,k);
	else 
		return query(tree[x].r,tree[y].r,mid+1,r,k-sum);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		init();
		rep(i,1,n) scanf("%d",&a[i]),v.push_back(a[i]);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		rep(i,1,n) update(rt[i-1],rt[i],1,n,getid(a[i]));
		rep(i,1,m){
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			printf("%d\n",v[query(rt[x-1],rt[y],1,n,k)-1]);
		}
	}
	return 0;
}

