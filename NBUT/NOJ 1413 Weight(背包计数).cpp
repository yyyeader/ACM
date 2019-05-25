#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e4+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;
const int MOD=100000007;

int dp[N];

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			for(int j=10000;j>=x;j--)
				dp[j]=(dp[j]+dp[j-x])%MOD;
		}
		for(int i=1;i<=10000;i++){
			if(dp[i])
				printf("%d %d\n",i,dp[i]);
		}
	}
	return 0;
}

