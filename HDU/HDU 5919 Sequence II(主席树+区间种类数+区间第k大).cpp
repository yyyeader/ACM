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
const int INF=0x3f3f3f3f;

struct node{int l,r,sum;}tree[N*40];
int cnt;
int rt[N],a[N],ans[N],last_pos[N];
vector<int>v;

void init(){
	cnt=0;
	memset(rt,0,sizeof(rt));
	memset(last_pos,0,sizeof(last_pos));
	v.clear();
}

int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

void update(int l,int r,int pre,int &cur,int pos,int op){
	tree[++cnt]=tree[pre];tree[cnt].sum+=op;cur=cnt;
	if(l==r) return;
	int mid=(l+r)/2;
	if(pos<=mid) update(l,mid,tree[pre].l,tree[cur].l,pos,op);
	else update(mid+1,r,tree[pre].r,tree[cur].r,pos,op);
}

int query(int l,int r,int cur,int L,int R){
	if(R<l||L>r) return 0;
	if(L<=l&&r<=R) return tree[cur].sum;
	int mid=(l+r)/2;
	return query(l,mid,tree[cur].l,L,R)+query(mid+1,r,tree[cur].r,L,R);
}

int find(int l,int r,int cur,int k){
	if(l==r) return l;
	int mid=(l+r)/2;
	int sum=tree[tree[cur].l].sum;
	if(k<=sum) return find(l,mid,tree[cur].l,k);
	else return find(mid+1,r,tree[cur].r,k-sum);
}

int main(){
	int T,cas=0;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		init();
		rep(i,1,n) scanf("%d",&a[i]),v.push_back(a[i]);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		per(i,n,1){
			int temp,p=getid(a[i]);
			if(!last_pos[p])
				update(1,n,rt[i+1],rt[i],i,1);
			else{
				update(1,n,rt[i+1],temp,last_pos[p],-1);
				update(1,n,temp,rt[i],i,1);
			}
			last_pos[p]=i;
		}
		rep(i,1,m){
			int l,r,sum;
			scanf("%d%d",&l,&r);
			l=(l+ans[i-1])%n+1;
			r=(r+ans[i-1])%n+1;
			if(l>r) swap(l,r);
			sum=query(1,n,rt[l],l,r);
			ans[i]=find(1,n,rt[l],(sum+1)/2);
		}
		printf("Case #%d:",++cas);
		rep(i,1,m) printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}
