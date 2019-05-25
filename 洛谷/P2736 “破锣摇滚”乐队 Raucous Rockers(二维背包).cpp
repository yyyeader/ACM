#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[25];
int dp[25][25];//dp[i][j]表示已经装了i个磁盘,且占用了第i个磁盘的容量为j时的最优解 

int main(){
	int n,t,m;
	while(cin>>n>>t>>m) {
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				for(int k=t;k>=a[i];k--){
					//dp[j-1][t]+1    将CD放在一张新磁盘中 
					//dp[j][k-a[i]]+1 一个磁盘放多张CD 
					//dp[j][k]        不要这张CD 
					dp[j][k]=max(dp[j][k],max(dp[j-1][t]+1,dp[j][k-a[i]]+1));
				}
			}
		}
		printf("%d\n",dp[m][t]);
	}
	return 0;
}
