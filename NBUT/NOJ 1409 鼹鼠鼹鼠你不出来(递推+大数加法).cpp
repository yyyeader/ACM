//0,1,2分别表示北、东、西
//dp[i][0]+=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
//dp[i][1]+=dp[i-1][0]+dp[i-1][1];
//dp[i][2]+=dp[i-1][0]+dp[i-1][2];
//根据上述方程化简得到dp[i]=dp[i-1]*2+dp[i-2]
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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

LL dp[105][200];

int main(){
	dp[1][0]=3;
	dp[2][0]=7;
	for(int i=3;i<=100;i++){
		for(int j=0;j<200;j++){
			dp[i][j]=dp[i-1][j]*2+dp[i-2][j];
		}
		for(int j=0;j<200;j++){
			if(dp[i][j]/10>0){
				dp[i][j+1]+=dp[i][j]/10;
				dp[i][j]%=10;
			}
		}
	}
	int n;
	while(cin>>n){
		bool f=false;
		for(int i=199;i>=0;i--){
			if(dp[n][i]!=0) f=true;
			if(f)
				printf("%d",dp[n][i]);
		}
		printf("\n");
	}
	return 0;
}

