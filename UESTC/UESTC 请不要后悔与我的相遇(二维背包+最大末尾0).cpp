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
const LL INF64=1e18;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL a[205];
int dp[205][6005];//dp[i][j]表示取了i个数,有j个5时最多的2

int main(){
	FAST_IO;
	memset(dp,-1,sizeof(dp));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		int five=0,two=0;
		while(a[i]&&a[i]%5==0){
			five++;
			a[i]/=5;
		}
		while(a[i]&&a[i]%2==0){
			two++;
			a[i]/=2;
		}
		for(int j=m;j>=1;j--){
			for(int k=five;k<=6000;k++){
				if(dp[j-1][k-five]!=-1)
					dp[j][k]=max(dp[j][k],dp[j-1][k-five]+two);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=6000;i++){
		ans=max(ans,min(dp[m][i],i));
	}
	cout<<ans<<endl;
	return 0;
}

