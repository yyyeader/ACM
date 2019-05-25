#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=305;
int s[N];
vector<int>v[N];
int n,m,dp[N][N];

void dfs(int u){
	dp[u][0]=0;
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		dfs(t);
		for(int j=m;j>=0;j--){
			for(int k=0;k<=j;k++)
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[t][k]);	
		} 
	}
	if(u!=0)
		for(int i=m;i>0;i--)
			dp[u][i]=dp[u][i-1]+s[u];
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>s[i];
		v[x].push_back(i); 
	}
	memset(dp,-1,sizeof(dp));
	dfs(0);
	printf("%d\n",dp[0][m]);
	return 0;
}
