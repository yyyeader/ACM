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
const int N=2e2+20;
const int M=120*120+200;
const int INF=0x3f3f3f3f;

int dp[N][M];

int main(){
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        memset(dp,0x3f,sizeof(dp));
        dp[0][m]=0;
        for(int i=1;i<=n;i++){
            int t1,t2,t3,f1,f2;
            cin>>t1>>t2>>t3>>f1>>f2;//花费t1秒，消耗f1体力；花费t2秒，不消耗体力；花费t3秒，增加f2体力
            //1
            for(int j=f1;j<=m;j++){
                if(dp[i-1][j]==INF)
                    continue;
                dp[i][j-f1]=min(dp[i][j-f1],dp[i-1][j]+t1);
            }
            //2
            for(int j=0;j<=m;j++){
                if(dp[i-1][j]==INF)
                    continue;
                dp[i][j]=min(dp[i][j],dp[i-1][j]+t2);
            }
            //3
            for(int j=0;j<=m;j++){
                if(dp[i-1][j]==INF)
                    continue;
                int k=min(j+f2,m);
                dp[i][k]=min(dp[i][k],dp[i-1][j]+t3);
            }
        }
        int ans=INF;
        for(int j=0;j<=m;j++){
            if(dp[n][j]==INF)
                continue;
            ans=min(ans,dp[n][j]);
        }
        printf("%d\n",ans);
    }
	return 0;
}
