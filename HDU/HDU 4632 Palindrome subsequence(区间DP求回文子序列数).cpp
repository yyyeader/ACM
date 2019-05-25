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
const int MOD=10007;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int dp[N][N];
char str[N];

int main(){
    int t,cas=0;
    cin>>t;
    while(t--){
        cin>>str;
        int n=strlen(str);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int len=1;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+MOD)%MOD;
                //如果str[i]==str[j],单独两个字符str[i],str[j]能组成一个回文串，同样也能跟[i-1,j+1]的所有回文串组成新的回文串
                if(str[i]==str[j])
                    dp[i][j]+=dp[i+1][j-1]+1;
            }
        }
        cout<<"Case "<<++cas<<": "<<dp[0][n-1]%MOD<<endl;
    }
	return 0;
}
