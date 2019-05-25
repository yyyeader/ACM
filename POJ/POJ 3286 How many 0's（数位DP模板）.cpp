#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=5e6+5;

LL top[105];
LL dp[50][50];

LL dfs(bool limit,bool lead,LL pos,LL num){
	if(pos==-1)
		return num;
	if(!limit&&!lead&&dp[pos][num]!=-1) return dp[pos][num];
	LL up=limit?top[pos]:9;
	LL ans=0;
	for(int i=0;i<=up;i++){
		ans+=dfs(limit&&i==up,lead&&i==0,pos-1,num+(i==0&&!lead));
	}
	if(!lead&&!limit) dp[pos][num]=ans;
	return ans;
}

LL solve(LL x){
	memset(dp,-1,sizeof(dp));
	int cnt=-1;
	while(x){
		top[++cnt]=x%10;
		x/=10;
	}
	return dfs(1,1,cnt,0);
}

int main(){
	FAST_IO;
	LL l,r;
	while(cin>>l>>r){
		if(l==-1&&r==-1)
			break;
		LL ans=0;
		if(l==0) l++,ans++;	
		ans+=solve(r)-solve(l-1);
		cout<<ans<<endl;
	}
	return 0;
}
