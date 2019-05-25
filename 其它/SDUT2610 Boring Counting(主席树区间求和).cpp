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

struct node{int l,r,sum;}tree[N*40];
int cnt,n,m;
int rt[N],a[N];
vector<int>v;

int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

void init(){
	cnt=0;
	memset(rt,0,sizeof(rt));
	v.clear();
}

void insert(int l,int r,int pre,int &cur,int pos){
	tree[++cnt]=tree[pre];tree[cnt].sum++;cur=cnt;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(pos<=mid) insert(l,mid,tree[pre].l,tree[cur].l,pos);
	else insert(mid+1,r,tree[pre].r,tree[cur].r,pos);
}

int query(int l,int r,int x,int y,int A,int B){
	if(r<A||l>B) return 0;
	//cout<<"l="<<l<<" r="<<r<<" "<<tree[y].sum-tree[x].sum<<endl;
	if(A<=l&&r<=B) return tree[y].sum-tree[x].sum;
	int mid=(l+r)>>1;
	return query(l,mid,tree[x].l,tree[y].l,A,B)+query(mid+1,r,tree[x].r,tree[y].r,A,B);
}

int main(){
	int T,cas=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		rep(i,1,n) scanf("%d",&a[i]),v.push_back(a[i]);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		rep(i,1,n) insert(1,v.size(),rt[i-1],rt[i],getid(a[i]));
		printf("Case #%d:\n",++cas);
		rep(i,1,m){
			int L,R,A,B;
			scanf("%d%d%d%d",&L,&R,&A,&B);
			int ans;
			if(A>B||B<v[0])
				ans=0;
			else{
				int pa=getid(A),pb=getid(B);
				if(pb==v.size()+1||v[pb-1]!=B) pb--;
				ans=query(1,v.size(),rt[L-1],rt[R],pa,pb);
			}
			printf("%d\n",ans);
		}	
	}
	return 0;
}

