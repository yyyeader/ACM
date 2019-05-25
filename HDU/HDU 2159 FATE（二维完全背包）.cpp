#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std; 
const int N=105;

int v[N],w[N];
int dp[N][N];

int main(){
	int n,m,k,s;
	while(~scanf("%d%d%d%d",&n,&m,&k,&s)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=k;i++){
			scanf("%d%d",&v[i],&w[i]);
		}
		for(int i=1;i<=k;i++){
			for(int j=w[i];j<=m;j++){
				for(int p=1;p<=s;p++){
					dp[j][p]=max(dp[j][p],dp[j-w[i]][p-1]+v[i]);
				}
			}
		}
		int ans=-1;
		for(int i=1;i<=m;i++){
			if(ans!=-1)
				break;
			for(int j=1;j<=s;j++){
				if(dp[i][j]>=n){
					ans=m-i;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
