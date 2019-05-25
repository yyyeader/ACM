#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e3+5;

int dp[N][50],pos[N],dis[N][N];//dis[i][j]表示在i~j之间建一个邮局的最小距离和 

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&pos[i]);
		}
		//预处理dis[i][j]
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			for(int j=i+1;j<=n;j++){
				dis[i][j]=dis[i][j-1]+pos[j]-pos[(i+j)/2];
			}
			dp[i][1]=dis[1][i];
		}
		
		for(int j=2;j<=m;j++){
			for(int i=j;i<=n;i++){
				for(int k=j-1;k<i;k++){
					dp[i][j]=min(dp[k][j-1]+dis[k+1][i],dp[i][j]);
				}
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
