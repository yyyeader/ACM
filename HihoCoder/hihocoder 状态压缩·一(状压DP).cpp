#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
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
const int N=4e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int a[N];
int dp[N][N];

int cal(int x){
	int res=0;
	while(x){
		if(x&1)
			res++;
		x>>=1;
	}
	return res;
}

int main(){
	int n,m,q;
	while(~scanf("%d%d%d",&n,&m,&q)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int lim=1<<(m-1),tmp=1<<(m-2);
		for(int i=1;i<=n;i++){
			for(int j=0;j<lim;j++){
				int next=j>>1;
				int cnt=cal(j);	//i-m+1..i-1有多少个1
				//选
				if(cnt<q)
					dp[i][next+tmp]=max(dp[i][next+tmp],dp[i-1][j]+a[i]);
				//不选 
				if(cnt<=q)
					dp[i][next]=max(dp[i][next],dp[i-1][j]);
			}
		}
		
		int ans=0;
		for(int i=0;i<lim;i++){
			ans=max(ans,dp[n][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
