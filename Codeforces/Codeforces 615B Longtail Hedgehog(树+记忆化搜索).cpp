#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<cctype>
#include<math.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
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
const int N=1e5+5;
const int M=2e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL ans;
int dp[N];//记录在树上以i为起点的最长递减子序列长度 
bool vis[N];
vector<int>v[N];

int dfs(int u,int len){
	if(dp[u]!=-1) return dp[u];
	int res=0;
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(u>t){
			res=max(res,dfs(t,len+1));
		}
	}
	res++;
	ans=max(ans,(LL)v[u].size()*res);
	return dp[u]=res;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=n;i>=1;i--){
		dfs(i,1);
	}
	printf("%lld\n",ans);
	return 0;
}
