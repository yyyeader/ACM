#include<stdio.h>
const int N=2e3+5;
int dp[N][N];
int a[N];

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int i,j,n;
	int ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}	
	//����˼�룺dp[i][j]�����i�δ��ײ��ã���j�δ�β����ʱ�����ֵ ,���ƾͺ��� 
	dp[1][0]=a[i];
	dp[0][1]=a[n-j+1];
	for(i=0;i<=n;i++){
		for(j=0;j<=n-i;j++){
		//�жϱ߽����� 
		if(j==0&&i==0)
			dp[i][j]=0;
		else if(j==0)
			dp[i][j]=dp[i-1][j]+a[i]*(i+j);
		else if(i==0)
			dp[i][j]=dp[i][j-1]+(i+j)*a[n-j+1];
		else
			dp[i][j]=max(dp[i-1][j]+a[i]*(i+j),dp[i][j-1]+a[n-j+1]*(i+j)); 
			if(dp[i][j]>ans)
				ans=dp[i][j];
		}
	}
	printf("%d\n",ans);
} 
