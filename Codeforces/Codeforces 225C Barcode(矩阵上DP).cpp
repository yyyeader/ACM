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
const int N=3e3+5;
const LL INF64=1e18;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int dp[N][2];  //dp[i][0]表示最后一列为'.'的最优解，dp[i][1]表示最后一列为'#'的最优解 
int sum[N][2]; //sum[i][0]表示前i列'#' 的前缀和，sum[i][1]表示前i列'.' 的前缀和 

int main(){
	memset(dp,0x3f,sizeof(dp));
	FAST_IO;
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char x;
			cin>>x;
			if(x=='#')
				sum[j][0]++;
			else
				sum[j][1]++;
		}
	}	
	for(int i=1;i<=m;i++){
		sum[i][0]+=sum[i-1][0];
		sum[i][1]+=sum[i-1][1];
	}

	dp[0][0]=dp[0][1]=0;
	for(int i=0;i<=m;i++){
		for(int j=x;j<=y;j++){
			dp[i+j][0]=min(dp[i+j][0],dp[i][1]+sum[i+j][0]-sum[i][0]);
			dp[i+j][1]=min(dp[i+j][1],dp[i][0]+sum[i+j][1]-sum[i][1]);
		}
	}
	cout<<min(dp[m][0],dp[m][1])<<endl;
	return 0;
}
