#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=1e2+5;
const int INF=0x3f3f3f3f;
const LL lim=(1LL<<32);

int mp[20]={6,2,5,5,4,5,6,3,7,6,6,5,4,5,5,4};
LL top[N],dp[N][N];		//dp[pos][val]其中pos表示数位,val表示当前需要消耗的电量 
char str[N];

LL dfs(bool limit,int pos,int val){
	if(pos==-1)	return val;
	if(!limit&&dp[pos][val]!=-1) return dp[pos][val];
	int up=limit?top[pos]:15;
	LL ans=0;
	for(int i=0;i<=up;i++){
		ans+=dfs(limit&&i==up,pos-1,val+mp[i]);
	}
	if(!limit) dp[pos][val]=ans;
	return ans;
}

LL solve(LL x){
	if(x==-1) return 0;
	int cnt=-1;
	while(x){
		top[++cnt]=x%16;
		x/=16;
	}
	while(cnt<7){
		top[++cnt]=0;
	}
	return dfs(1,cnt,0);
}

int main(){
	int t;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	while(t--){
		LL n,st;
		scanf("%lld %llx",&n,&st);
		LL ans;
		if(st+n-1>=lim){
			ans=solve((st+n-1)%lim)+solve(lim-1)-solve(st-1);
		}
		else{
			ans=solve(st+n-1)-solve(st-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

