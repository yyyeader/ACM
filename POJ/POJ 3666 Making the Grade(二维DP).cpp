#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=2e3+5;

LL a[N],dp[N][N],Hash[N];//dp[i][j]表示将1~i变为不降序列，且把第i个数改为第Hash[j]的最小花费 
						 
LL Abs(LL a){
	return a>=0?a:-a;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Hash[i]=a[i];
	}
	sort(Hash+1,Hash+1+n);
	int cnt=unique(Hash+1,Hash+1+n)-Hash;
	
	for(int j=1;j<cnt;j++){
		dp[1][j]=Abs(Hash[j]-a[1]);
	}
	for(int i=2;i<=n;i++){
		LL tmp=1e18;
		for(int j=1;j<cnt;j++){
			tmp=min(tmp,dp[i-1][j]);
			dp[i][j]=Abs(Hash[j]-a[i]);
			dp[i][j]+=tmp;
		}
	}
	LL ans=1e18;
	for(int j=1;j<cnt;j++)
		ans=min(ans,dp[n][j]); 
	cout<<ans<<endl;
	return 0;
}
