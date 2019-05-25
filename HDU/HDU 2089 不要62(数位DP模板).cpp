#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[25][25],a[25];

ll dfs(ll pos,ll state,ll limit){//state表示前一位是否为6,不用前导0
	if(pos==0) return 1;
	if(!limit&&dp[pos][state]!=-1) return dp[pos][state];
	ll up=limit?a[pos]:9;
	ll ans=0;
	for(int i=0;i<=up;i++){
		if(state&&i==2)	continue;
		if(i==4)	continue;
		ans+=dfs(pos-1,i==6,limit&&i==up);
	}
	if(!limit) dp[pos][state]=ans;
	return ans;
}

ll solve(ll num){
	memset(dp,-1,sizeof(dp));
	ll top=0;
	while(num){
		a[++top]=num%10;
		num/=10;
	}
	return dfs(top,0,1);
}

int main(){
	ios::sync_with_stdio(false);
	ll l,r;
	while(cin>>l>>r&&(l||r)){
		ll ans=0;
		if(l==0) ans++,l++;
		ans+=solve(r)-solve(l-1);
		cout<<ans<<endl;
	}
	return 0;
}
