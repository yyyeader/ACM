#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[25][25],a[25];

ll dfs(ll pos,ll state,ll lead,ll limit){//state表示0的个数 ,lead表示有无先导0 
	if(pos==0) return state;
	if(!limit&&!lead&&dp[pos][state]!=-1) 	return dp[pos][state];
	ll up=limit?a[pos]:9;
	ll ans=0;
	for(int i=0;i<=up;i++){
		ans+=dfs(pos-1,state+(!lead&&i==0),lead&&i==0,limit&&i==up);
	}
	if(!limit&&!lead) dp[pos][state]=ans;
	return ans;
}

ll solve(ll num){
	memset(dp,-1,sizeof(dp));
	ll top=0;
	while(num){
		a[++top]=num%10;
		num/=10;
	}
	return dfs(top,0,1,1);
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll l,r;
		cin>>l>>r;
		ll ans=0;
		if(l==0) ans++,l++;
		ans+=solve(r)-solve(l-1);
		cout<<"Case "<<i<<": ";
		cout<<ans<<endl;
	}
} 
