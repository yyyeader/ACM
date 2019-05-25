#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e3+5;
const int inf=1<<30;
int a[N];
int dp[N][N];

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);	
				
		for(int i=n;i>=1;i--){
			for(int j=i;j<=n;j++){
				dp[i][j]=max(dp[i+1][j]+a[i]*(n-j+i),dp[i][j-1]+a[j]*(n-j+i));
			}
		}
		printf("%d\n",dp[1][n]);
	}
	return 0;
}
