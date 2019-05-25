#include<cstdio>
#include<cmath> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int dp[N][15];
int a[N][15];//a[i][j]表示在时刻i,位置j上掉落的馅饼数 

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		int mt=0;
		for(int i=1;i<=n;i++){
			int x,t;
			scanf("%d%d",&x,&t);
			a[t][x]++;
			mt=max(mt,t);
		}
		int ans=0;
		for(int i=1;i<=mt;i++){
			for(int j=0;j<=10;j++){
				//需要特判这个时间能否到达该位置 
				if(i<abs(5-j))
					continue;
				if(j==0)
					dp[i][j]=max(dp[i-1][j],dp[i-1][1])+a[i][j];
				else
					dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]))+a[i][j];		
				ans=max(ans,dp[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
