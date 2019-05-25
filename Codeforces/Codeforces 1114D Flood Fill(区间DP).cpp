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
const int N=5e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int a[N],dp[N][N][2];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[i][i][0]=dp[i][i][1]=0;
	for(int len=1;len<=n;len++){
		for(int i=1;i+len<=n;i++){
			int j=i+len;
			dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(a[i]!=a[i+1]));
			dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(a[i]!=a[j]));
			dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(a[i]!=a[j]));
			dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(a[j-1]!=a[j]));
		}
	}
	cout<<min(dp[1][n][0],dp[1][n][1])<<endl;
	return 0;
}

