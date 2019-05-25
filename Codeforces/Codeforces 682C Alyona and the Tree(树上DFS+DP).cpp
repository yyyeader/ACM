#include<bits/stdc++.h>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=2e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

struct node{
	int to,w;
	node(int to,int w):to(to),w(w){}
};

int ans;
int a[N];
vector<node>v[N];

void dfs(int u,LL dis,int fa){
	if(dis>a[u]) return;	//dis(v,u)>a[u]不符合 
	ans++;
	for(int i=0;i<v[u].size();i++){
		node t=v[u][i];
		if(t.to==fa) continue;
		dfs(t.to,max(0LL,dis+t.w),u);//dis<0则取0 
	}
}

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		int to,w;
		cin>>to>>w;
		v[i].push_back(node(to,w));
		v[to].push_back(node(i,w));
	}
	dfs(1,0,-1);
	cout<<n-ans<<endl;
	return 0;
}

