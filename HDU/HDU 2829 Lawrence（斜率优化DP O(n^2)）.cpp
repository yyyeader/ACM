#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e3+5;
int dp[N][N],sum[N],cost[N],q[N],head,tail;

//yj-yk/xj-xk 
double Slope(int m,int k,int j){
	return double(dp[j][m-1]+sum[j]*sum[j]-cost[j]-dp[k][m-1]-sum[k]*sum[k]+cost[k])/(sum[j]-sum[k]);
}

//dp[i][j]=min{dp[k][j-1]+cost[i]-cost[k]-sum[k]*(sum[i]-sum[k])} 
int getDP(int i,int j,int k){
	return dp[k][j-1]+cost[i]-cost[k]-sum[k]*(sum[i]-sum[k]);
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(m==0&&n==0)
			break;
		memset(cost,0,sizeof(cost));
		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&sum[i]);
			sum[i]+=sum[i-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				cost[i]+=(sum[j]-sum[j-1])*(sum[i]-sum[j]);
			}
			dp[i][1]=cost[i];
		}
		for(int j=2;j<=m+1;j++){
			head=tail=0;
			q[tail++]=j-1;
			for(int i=j;i<=n;i++){
				while(head+1<tail&&Slope(j,q[head],q[head+1])<=sum[i]){			
					head++;
				}
				dp[i][j]=getDP(i,j,q[head]);
				while(head+1<tail&&Slope(j,q[tail-2],q[tail-1])>=Slope(j,q[tail-1],i)){
					tail--;
				}
				q[tail++]=i;		
			}
		}
		printf("%d\n",dp[n][m+1]);
	}
	return 0;
}
