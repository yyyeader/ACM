#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std; 
const int N=2e2+5;
const int INF=0x3f3f3f3f;

int a[N],dp[N][N],dp2[N][N],sum[N];

int main(){
	int n;
	scanf("%d",&n);
	memset(dp,0x3f,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++){
		sum[i]=sum[i-1]+a[i];
		dp[i][i]=0;
	}
	for(int d=1;d<n;d++){
		for(int i=1;i<=2*n-d;i++){
			int j=i+d;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
				dp2[i][j]=max(dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	int ans1=INF,ans2=0,d=n-1;
	for(int i=1;i<=2*n-d;i++){
		int j=i+d;
		ans1=min(ans1,dp[i][j]);
		ans2=max(ans2,dp2[i][j]);
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
