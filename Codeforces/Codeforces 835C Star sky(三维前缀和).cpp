#include<iostream> 
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[11][105][105],star[11][105][105];

int main(){
	int n,q,c;
	scanf("%d%d%d",&n,&q,&c);
	for(int i=1;i<=n;i++){
		int x,y,s;
		scanf("%d%d%d",&x,&y,&s);
		star[s][x][y]++;
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			for(int k=0;k<=10;k++){
				dp[k][i][j]=dp[k][i-1][j]+dp[k][i][j-1]-dp[k][i-1][j-1]+star[k][i][j];
			}		
		}
	}
	for(int i=1;i<=q;i++){
		int t,x1,y1,x2,y2,ans=0;
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		for(int j=0;j<=10;j++){
			//注意边界也要包含，所以是x1-1,y1-1. 
			int num=dp[j][x2][y2]-dp[j][x1-1][y2]-dp[j][x2][y1-1]+dp[j][x1-1][y1-1];
			ans+=((j+t)%(c+1))*num;
		}
		printf("%d\n",ans);
	}
	return 0;
}
