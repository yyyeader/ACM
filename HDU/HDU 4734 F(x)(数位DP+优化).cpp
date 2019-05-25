#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll dp[25][4700],a[25],lim;

ll dfs(ll pos,ll state,ll limit){//state记录数位和的大小	 
	if(pos==0) return state<=lim;
	if(state>lim) return 0;
	if(!limit&&dp[pos][lim-state]!=-1) return dp[pos][lim-state];//以当前值与lim的差为状态进行记录	 
	ll ans=0;
	ll up=limit?a[pos]:9;
	for(int i=0;i<=up;i++){
		ans+=dfs(pos-1,state+i*(1<<(pos-1)),limit&&i==up);
	}
	if(!limit) dp[pos][lim-state]=ans;
	return ans;
}

ll f(ll x){
    ll count=0;
	ll ans=0;  
    while(x){
    	ans+=(1<<count)*(x%10);
    	count++;
    	x/=10;
	} 
	return ans; 
}

ll solve(ll num){
	ll top=0;
	while(num){
		a[++top]=num%10;
		num/=10;
	}
	return dfs(top,0,1);
}

int main(){
	ios::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a,r;
		cin>>a>>r;
		ll ans=0;
		lim=f(a);
		ans+=solve(r);
		cout<<"Case #"<<i<<": "<<ans<<endl; 
	}
	return 0;
}
