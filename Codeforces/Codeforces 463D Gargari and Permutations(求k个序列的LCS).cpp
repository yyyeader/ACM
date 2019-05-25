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
const int N=2e3+5;
const LL INF64=1e18;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int dp[N],a[10][N],pos[10][N];//dp[i]表示以i结尾的最长公共子序列长度 

int main(){
	FAST_IO;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			pos[i][a[i][j]]=j;
		}
	}
	
	for(int i=1;i<=n;i++){
		dp[a[1][i]]=1;
		for(int j=1;j<i;j++){
			int t1=a[1][i],t2=a[1][j];
			bool flag=true;
			for(int k=2;k<=q;k++){
				if(pos[k][t1]<=pos[k][t2]){
					flag=false;
					break;
				}
			}
			if(flag)
				dp[t1]=max(dp[t1],dp[t2]+1);
		}
	}
	
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
