#include<stdio.h>
int dp[35][35];
int main(){
	freopen("in.txt","r",stdin);
	dp[1][0]=1;
	int m,n,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++){
		//第一个人和第n个人的时候需要单独处理，n个同学站成了一个圆圈，所以1左边是n，n右边是1 
		dp[1][i]=dp[2][i-1]+dp[n][i-1];
		dp[n][i]=dp[1][i-1]+dp[n-1][i-1];
		for(j=2;j<n;j++){
			//每个同学可以把球传给自己左右的两个同学中的一个 
			dp[j][i]=dp[j-1][i-1]+dp[j+1][i-1]; 
		}
	}
	printf("%d\n",dp[1][n]);
} 
