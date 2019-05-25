#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
const int N=120;

int top,MOD;
int a[N];
LL dp[20][N][N];//dp[i][j][k]表示第i位,数字和为j,%MOD=k时的方案数 

LL dfs(int pos,int sum,int num,bool limit){
	if(pos==0){
		if(sum==0&&num==0) return 1;
		return 0;
	}
	if(!limit&&dp[pos][sum][num]!=-1) return dp[pos][sum][num];
	int up=limit?a[pos]:9;
	LL ans=0;
	for(int i=0;i<=up;i++){
		if(sum-i<0) continue;
		ans+=dfs(pos-1,sum-i,(num*10+i)%MOD,limit&&i==up);	
	}
	if(!limit) dp[pos][sum][num]=ans;
	return ans;
}

LL solve(LL x){
	top=0;
	while(x){
		a[++top]=x%10;
		x/=10;
	}
	LL ans=0;
	//数字各数位之和在1~9*top之间 
	for(int i=1;i<=9*top;i++){
		MOD=i;
		memset(dp,-1,sizeof(dp));
		ans+=dfs(top,i,0,true);
	}
	return ans;
}

int main(){
	LL n;
	while(~scanf("%lld",&n)){
		LL ans=solve(n);
		printf("%lld\n",ans);
	}
	return 0;
}
