#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=5e4+5;
LL dp[N];
LL A[300][300];//A[i][j]表示第i天消耗j可以获得的价值 
int v;//总体积 

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(A,0,sizeof(A));
		int n,m,k;
		scanf("%d%d%d",&n,&m,&v);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%lld",&A[i][j]);
				A[i][j]+=A[i][j-1];
			}
		}
	    for(int i=1;i<=n;i++)
	        for(int j=v;j>=0;j--)
	            for(int k=1;k<=min(j,m);k++)
	                dp[j]=max(dp[j],dp[j-k]+A[i][k]);
    	printf("%lld\n",dp[v]);
	}	
} 
