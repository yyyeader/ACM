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
const int N=5e2+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int dp[N][N];
char str[N];

int main(){
    while(~scanf("%s",str)&&strcmp(str,"end")){
        int n=strlen(str);
        memset(dp,0,sizeof(dp));
        for(int len=1;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                if(str[i]=='('&&str[j]==')'||(str[i]=='['&&str[j]==']')){
                    dp[i][j]=dp[i+1][j-1]+1;
                }
                for(int k=i;k<j;k++){
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
        printf("%d\n",dp[0][n-1]*2);
    }
	return 0;
}
