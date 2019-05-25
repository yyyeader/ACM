#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=1e5+5;
const int M=15;
const LL MOD=1e9+7;

int dp[N][M];//dp[i][j]表示长度为i，最末尾的数字为j的子序列方案数 
int sum[N];  //sum[i]代表长度为i的子序列个数 

int main(){
	FAST_IO;
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k)){
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		sum[0]=1;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			for(int j=i;j>=max(1,i-m);j--){
				//解释一下,每次多出一个数字x，那么x可以跟sum[j-1]中每一个子序列都组成长度为j的子序列，所以sum[j]+=sum[j-1]
				//然后考虑重复，再减去已有的以x为结尾长度为j的子序列，即sum[j]+=sum[j-1]-dp[j][x]
				sum[j]=(sum[j]+sum[j-1]-dp[j][x]+MOD)%MOD;
				dp[j][x]=sum[j-1];
			}
		}
		printf("%d\n",sum[n-m]);
	}
	return 0;
}

