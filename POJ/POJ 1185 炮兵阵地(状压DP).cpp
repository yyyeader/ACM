#include<iostream>
#include<cstdio>
#include<cstring>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=105;
const int M=80;
int n,m;
int dp[N][M][M],sta[N][M],sum[N];//dp[i][j][k]表示在第i行状态j且上一行为状态k时的最优解 
char mp[N][15];

//求出每一行的合法状态
void dfs(int row,int temp){
	int lim=(1<<m);
	for(int i=0;i<lim;i++){
		if(i&(i<<1)||i&(i<<2)||i&temp) continue;
		sta[row][sum[row]++]=i;
	}
}

//计算1的个数 
int cal(int x){
	int cnt=0;
	for(int i=0;i<m;i++){
		int tmp=(1<<i);
		if(tmp&x)
			cnt++;
	}
	return cnt;
}

int main(){
	FAST_IO;
	while(cin>>n>>m){
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			cin>>mp[i];
			int temp=0;
			for(int j=0;j<m;j++){
				if(mp[i][j]=='H')
					temp|=(1<<(m-j-1));
			}
			dfs(i,temp);
		}
		int ans=0;
		//第一行和第二行单独计算 
		for(int i=0;i<sum[0];i++){
			dp[0][i][0]=cal(sta[0][i]);	
			ans=max(ans,dp[0][i][0]);
		}
		for(int i=0;i<sum[1];i++){
			for(int j=0;j<sum[0];j++){
				if(sta[0][j]&sta[1][i]) continue;
				dp[1][i][j]=dp[0][j][0]+cal(sta[1][i]);
				ans=max(ans,dp[1][i][j]);
			}
		}

		for(int i=2;i<n;i++){
			for(int j=0;j<sum[i];j++){
				for(int k=0;k<sum[i-1];k++){
					for(int p=0;p<sum[i-2];p++){
						if(sta[i][j]&sta[i-1][k]||sta[i][j]&sta[i-2][p]) continue;
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][p]+cal(sta[i][j]));
						ans=max(ans,dp[i][j][k]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
