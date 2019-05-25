#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=25;
const int M=500;
const int MOD= 100000000;
int m;
LL dp[N][M],sum[N],sta[N][M];//dp[i][j]表示第i行状态j时的方案数 

//计算每行的合理状态 
void dfs(int row,int temp){
	int lim=(1<<m);
	for(int i=0;i<lim;i++){
		if(i&(i<<1)||i&temp) continue;
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
	int n;
	while(cin>>n>>m){
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(int i=0;i<n;i++){
			int tmp=0;
			for(int j=0;j<m;j++){
				int x;
				cin>>x;
				if(x==0)
					tmp|=(1<<(m-j-1));
			}
			dfs(i,tmp);
		}
		for(int i=0;i<n;i++){
			if(i==0){
				for(int j=0;j<sum[i];j++)
					dp[i][j]=1;
				continue;
			}
			for(int j=0;j<sum[i];j++){
				for(int k=0;k<sum[i-1];k++){
					if(sta[i][j]&sta[i-1][k]) continue;
					dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
				}
			}
		}
		LL ans=0;
		for(int i=0;i<sum[n-1];i++){
			ans=(ans+dp[n-1][i])%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
