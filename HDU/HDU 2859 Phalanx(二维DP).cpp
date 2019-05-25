#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+5;
char map[N][N];
int dp[N][N];

int main(){
	int n;
	while(scanf("%d",&n)&&n){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=n;j++){
				scanf("%c",&map[i][j]);
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==1||j==n){
					dp[i][j]=1;
					continue;
				}
				int t1=i,t2=j,cnt=0;
				while(t1>=1&&t2<=n&&map[t1][j]==map[i][t2]){
					t1--;
					t2++;
					cnt++;
				}
				if(cnt>=dp[i-1][j+1]+1)
					dp[i][j]=dp[i-1][j+1]+1;
				else
					dp[i][j]=cnt;	
				ans=max(ans,dp[i][j]);
			}
		}
		printf("%d\n",ans);
	}
}
