#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e2+5;
int a[N][N],dp[N][N];
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,k;

int dfs(int x,int y){
	int res=0;
	if(dp[x][y]) return dp[x][y];
	for(int i=0;i<4;i++){
		for(int j=1;j<=k;j++){
			int xx=x+d[i][0]*j;
			int yy=y+d[i][1]*j;
			if(xx<1||xx>n||yy<1||yy>n)
				continue;
			if(a[xx][yy]>a[x][y])
				res=max(res,dfs(xx,yy));
		}
	}
	dp[x][y]=res+a[x][y];
	return dp[x][y];
}

int main(){
	while(~scanf("%d%d",&n,&k)){	
		if(n==-1&&k==-1)
			break;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		printf("%d\n",dfs(1,1));
	}
	return 0;
} 
