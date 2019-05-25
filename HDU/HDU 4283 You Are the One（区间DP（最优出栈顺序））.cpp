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
const int N=1e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL d[N],sum[N];
LL dp[N][N];

int main(){
    int t,cas=0;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>d[i];
            sum[i]=sum[i-1]+d[i];
        }
        for(int len=1;len<n;len++){
            for(int i=1;i+len<=n;i++){
                int j=i+len;
                dp[i][j]=INF;
                for(int k=i;k<=j;k++){
                    dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]+d[i]*(k-i)+(sum[j]-sum[k])*(k-i+1));
                }
            }
        }
        cout<<"Case #"<<++cas<<": "<<dp[1][n]<<endl;
    }
	return 0;
}
