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
const int N=2e2+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int sum[N];
int dp[N][N][N];

int main(){
    int n,l,r;
    while(cin>>n>>l>>r){
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>sum[i];
            sum[i]+=sum[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                dp[i][j][j-i+1]=0;
            }
        }
        for(int len=1;len<n;len++){
            for(int i=1;i+len<=n;i++){
                int j=i+len;
                //p要从2开始,而不是从l开始
                for(int p=2;p<=r;p++){
                    for(int k=i;k<j;k++){
                        if(k-i+1<p-1) continue;
                        dp[i][j][p]=min(dp[i][j][p],dp[i][k][p-1]+dp[k+1][j][1]);
                    }
                }
                for(int p=l;p<=r;p++){
                    dp[i][j][1]=min(dp[i][j][1],dp[i][j][p]+sum[j]-sum[i-1]);
                }
            }
        }
        if(dp[1][n][1]==INF)
            cout<<0<<endl;
        else
            cout<<dp[1][n][1]<<endl;
    }
	return 0;
}
