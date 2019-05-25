#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1e3+5;
const long long INF=0x3f3f3f3f;
LL sum[N],dp[N][N],cost[N][N],s[N][N];//s[i][j]记录dp[i][j]的最优切割点 

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0)
			break;
		memset(cost,0,sizeof(cost));
		memset(dp,INF,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%lld",&sum[i]);
			sum[i]+=sum[i-1];
			s[i][0]=0;
		}
		//计算cost[i][j]
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				cost[1][i]+=(sum[j]-sum[j-1])*(sum[i]-sum[j]);
			}
			dp[i][0]=cost[1][i];
		}
		for(int k=1;k<=n;k++){
			for(int i=k+1;i<=n;i++){
				cost[k][i]=cost[1][i]-cost[1][k-1]-sum[k-1]*(sum[i]-sum[k-1]);
			}
		}
		
		//j为轰炸次数,当i = 1或者j = n时为边界对s的处理就是为了处理这些边界
		for(int j=1;j<=m;j++){
			s[n+1][j]=n-1;
			for(int i=n;i>=j;i--){
				for(int k=s[i][j-1];k<=s[i+1][j];k++){
					LL tmp=dp[k][j-1]+cost[k+1][i];			
					if(tmp<dp[i][j]){
						dp[i][j]=tmp;
						s[i][j]=k;
					}
				}
			}	
		}
		printf("%lld\n",dp[n][m]);
	}
	return 0;
}
