#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[50][50][50],a[50];//dp记录三个状态，位置，0的个数，1的个数 
//按二进制位进行数位dp 
ll dfs(ll pos,ll zeros,ll ones,ll lead,ll limit){
	if(pos==0) return zeros>=ones;
	if(!lead&&!limit&&dp[pos][zeros][ones]!=-1)	return dp[pos][zeros][ones];
	ll ans=0;
	ll up=limit?a[pos]:1;
	for(int i=0;i<=up;i++){
		ans+=dfs(pos-1,zeros+(!lead&&i==0),ones+(i==1),lead&&i==0,limit&&i==up);
	}
	if(!lead&&!limit) dp[pos][zeros][ones]=ans;
	return ans;
}

ll solve(ll num){
	ll top=0;
	memset(dp,-1,sizeof(dp));
	while(num){
		a[++top]=num%2;
		num/=2;
	}
	return dfs(top,0,0,1,1);
}

int main(){
	ios::sync_with_stdio(false);
	ll l,r;
	while(cin>>l>>r){
		ll ans=0;
		if(l==0) l++,ans++;
		ans+=solve(r)-solve(l-1);
		cout<<ans<<endl;
	}
}

