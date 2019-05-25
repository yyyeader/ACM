#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=2e3+5;
const int MOD=1e3;

int	ans[N];
int dp[N][N];//dp[i][j]表示将前i个数分j组的方案数 

int main(){
	dp[1][1]=1;
	for(int i=2;i<N;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%MOD;
		}
	}
	for(int i=1;i<N;i++){
		for(int j=1;j<=i;j++){
			ans[i]=(ans[i]+dp[i][j])%MOD;
		}
	}
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		cout<<ans[x]<<endl;
	}
	return 0;
}
