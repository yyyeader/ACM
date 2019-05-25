#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

LL ans;
LL sum[N],dp[N],a[N],f[N];

vector<int>v[N];

void dfs(int u,int fa,int path){
	dp[u]=a[u]*path;
	sum[u]=a[u];
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(t==fa) continue;
		f[t]=u;
		dfs(t,u,path+1);
		sum[u]+=sum[t];
		dp[u]+=dp[t];
	}
}

void find(int u,int fa){
	ans=max(dp[u],ans);
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(t==fa) continue;
		dp[t]=dp[u]+sum[1]-2*sum[t];
		find(t,u);
	}
}

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0,0);
	find(1,0);
	cout<<ans<<endl;
	return 0;
}

