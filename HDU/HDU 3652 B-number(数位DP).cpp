#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
const int N=200;
const int MOD=13; 

int top;
int a[N];
LL dp[25][N][3];//dp[i][j][k] i表示第i位,j表示当前数%MOD=j,k=1表示前一位取1，k=2表示出现过“13”

LL dfs(int pos,int num,int have,bool limit){
	if(pos==0){
		if(num==0&&have==2) return 1;
		return 0;
	}
	if(!limit&&dp[pos][num][have]!=-1) return dp[pos][num][have];
	int up=limit?a[pos]:9;
	LL ans=0;
	for(int i=0;i<=up;i++){
		if(have == 0 && i == 1)
			ans+=dfs(pos-1,(num*10+i)%MOD,1,limit&&i==up);	
		else if(have == 1 && i == 3)
			ans+=dfs(pos-1,(num*10+i)%MOD,2,limit&&i==up);
		else if(have == 1 && i != 1)
			ans+=dfs(pos-1,(num*10+i)%MOD,0,limit&&i==up);
		else
			ans+=dfs(pos-1,(num*10+i)%MOD,have,limit&&i==up);
	}
	if(!limit) dp[pos][num][have]=ans;
	return ans;
}

LL solve(LL x){
	top=0;
	while(x){
		a[++top]=x%10;
		x/=10;
	}
	LL ans=0;
	memset(dp,-1,sizeof(dp));
	return dfs(top,0,0,true);
}

int main(){
	LL n;
	while(~scanf("%lld",&n)){
		LL ans=solve(n);
		printf("%lld\n",ans);
	}
	return 0;
}
