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
const int N=5e4+5;
const int M=2e5+5;
const int INF=0x3f3f3f3f;

struct node{int l,r,sum;}tree[N*40];
int cnt;
int a[N],rt[N],last_pos[N];
vector<int>v;

int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}

void update(int l,int r,int pre,int &cur,int pos,int val) {
	tree[++cnt]=tree[pre];tree[cnt].sum+=val;cur=cnt;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,tree[pre].l,tree[cur].l,pos,val);
	else update(mid+1,r,tree[pre].r,tree[cur].r,pos,val);
}

int query(int l,int r,int cur,int L,int R){
	if(r<L||l>R) return 0;
	if(L<=l&&r<=R) return tree[cur].sum;
	int mid=(l+r)>>1;
	return query(l,mid,tree[cur].l,L,R)+query(mid+1,r,tree[cur].r,L,R);
}

int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	rep(i,1,n){
		int p=getid(a[i]);
		int temp;
		if(!last_pos[p]) update(1,n,rt[i-1],rt[i],i,1);
		else{
			update(1,n,rt[i-1],temp,last_pos[p],-1);
			update(1,n,temp,rt[i],i,1);
		}
		last_pos[p]=i;
	}
	int m;
	scanf("%d",&m);
	rep(i,1,m){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,n,rt[r],l,r));
	}
	return 0;
}

