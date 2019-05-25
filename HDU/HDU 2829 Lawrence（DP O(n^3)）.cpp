#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e3+5;

int cost[N][N],dp[N][N],sum[N],a[N];//dp[i][j]表示第i个位置分j段的价值 

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(m==0&&n==0)
			break;
		sum[0]=0;
		memset(dp,0x3f,sizeof(dp));
		memset(cost,0,sizeof(cost));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]=a[i]+sum[i-1];
		}
		
		//处理cost[i][j]，使其表示i~j段价值 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				cost[1][i]+=a[j]*(sum[i]-sum[j]); 
			}
			dp[i][1]=cost[1][i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cost[i][j]=cost[1][j]-cost[1][i-1]-sum[i-1]*(sum[j]-sum[i-1]);
			}
		}

		for(int j=2;j<=m+1;j++){
			for(int i=j;i<=n;i++){
				for(int k=j-1;k<i;k++){
					dp[i][j]=min(dp[k][j-1]+cost[k+1][i],dp[i][j]);
				}
			}
		}
		printf("%d\n",dp[n][m+1]);
	}
	return 0;
}
