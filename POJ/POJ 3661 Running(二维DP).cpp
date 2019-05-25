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
const int N=1e4+5;
const int M=1e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int d[N];
int dp[N][M];

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",&d[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0];
            for(int j=1;j<=min(i,m);j++){
                dp[i][0]=max(dp[i][0],dp[i-j][j]);
            }
            for(int j=1;j<=m;j++){
               dp[i][j]=dp[i-1][j-1]+d[i];
            }
        }
        printf("%d\n",dp[n][0]);
    }
	return 0;
}
