#include<bits/stdc++.h>
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
const int N=505;
const int INF=0x3f3f3f3f;
const double eps=1e-10;


LL arr[N];
LL dp[2][N][N];//dp[i][j][k]表示到第i个程序员为止，打了j行代码，k个错误的方案数 

int main(){
	FAST_IO;
	LL n,m,b,mod;
	while(cin>>n>>m>>b>>mod){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		dp[0][0][0]=1;
		for(int i=1;i<=n;i++){
			int now=i&1,pre=now^1;
			for(int j=0;j<=m;j++){
				for(int k=0;k<=b;k++){
					dp[now][j][k]=dp[pre][j][k];
					if(j>0&&k>=arr[i])
						dp[now][j][k]=(dp[now][j][k]+dp[now][j-1][k-arr[i]])%mod;
				}
			}
		}
		LL ans=0;
		for(int i=0;i<=b;i++){
			ans=(ans+dp[n&1][m][i])%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
