#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ll;
const ll MOD=1e9+7;
int a[25];
ll power[25];
struct node{
	ll n,s,sq;//符合条件的数的个数，各位值之和，平方和 
}dp[25][10][10];

node dfs(ll pos,ll mod1,ll mod2,bool limit){//每次的value不一样,不能直接存平方和的值之和 
	if(pos==0){
		node t;
		t.n=(mod1&&mod2);
		t.s=t.sq=0;
		return t;
	}
	if(!limit&&dp[pos][mod1][mod2].n!=-1) return dp[pos][mod1][mod2];
	node ans,temp;
	ans.n=ans.s=ans.sq=0;
	int up=limit?a[pos]:9;
	for(int i=0;i<=up;i++){
		if(i==7)	continue; 
		temp = dfs(pos-1,(mod1*10+i)%7,(mod2+i)%7,limit && (i == up));  
      	ans.n=(ans.n + temp.n)%MOD;  
     	ans.s=(ans.s+temp.s+((i*power[pos])%MOD *temp.n) % MOD) % MOD;  
      	ans.sq=(ans.sq+temp.sq+((2*i*power[pos])%MOD*temp.s)%MOD)%MOD; 
		ans.sq=(ans.sq+(((i*i*power[pos])%MOD*power[pos])%MOD*temp.n)%MOD)%MOD; 
	}
	if(!limit)	dp[pos][mod1][mod2]=ans;
	return ans;
}

ll solve(ll n){
	ll top=0;
	while(n){
		a[++top]=n%10;
		n/=10;		
	}
	node ans=dfs(top,0,0,true);
	return ans.sq;	
}
  
int main(){
	memset(dp,-1,sizeof(dp));
	power[1]=1;
	for(int i=2;i<=19;i++){
		power[i]=(power[i-1]*10)%MOD;
	}	
	int t;
	scanf("%d",&t);
	while(t--){
		ll l,r,ans;
		scanf("%lld %lld",&l,&r);
		ans=(solve(r)-solve(l-1)+MOD)%MOD;//可能出现负数，所以要补回来 
		printf("%lld\n",ans);
	}
	return 0; 
}
