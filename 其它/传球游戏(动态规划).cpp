#include<stdio.h>
int dp[35][35];
int main(){
	freopen("in.txt","r",stdin);
	dp[1][0]=1;
	int m,n,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++){
		//��һ���˺͵�n���˵�ʱ����Ҫ��������n��ͬѧվ����һ��ԲȦ������1�����n��n�ұ���1 
		dp[1][i]=dp[2][i-1]+dp[n][i-1];
		dp[n][i]=dp[1][i-1]+dp[n-1][i-1];
		for(j=2;j<n;j++){
			//ÿ��ͬѧ���԰��򴫸��Լ����ҵ�����ͬѧ�е�һ�� 
			dp[j][i]=dp[j-1][i-1]+dp[j+1][i-1]; 
		}
	}
	printf("%d\n",dp[1][n]);
} 
