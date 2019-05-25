#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=1e2+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int top[N];
LL dp[N][N];

//为什么不能用pre==0判断而要用lead,因为(00)98 ,1098用pre==0判断会混为一谈 
LL dfs(bool lead,bool limit,int pos,int pre){
	if(pos==-1)	return 1;
	if(!lead&&!limit&&dp[pos][pre]!=-1) return dp[pos][pre];
	int up=limit?top[pos]:9;
	LL ans=0;
	for(int i=0;i<=up;i++){
		if(!lead&&abs(pre-i)<2) continue;
		ans+=dfs(lead&&(i==0),limit&&(i==up),pos-1,i);
	}
	if(!lead&&!limit) dp[pos][pre]=ans;
	return ans;
}

LL solve(LL x){
	if(x==-1) return 0;
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
	LL a,b;
	while(cin>>a>>b){
		cout<<solve(b)-solve(a-1)<<endl;
	}
	return 0;
}

