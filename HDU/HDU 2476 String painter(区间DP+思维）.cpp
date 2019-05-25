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

int ans[N],dp[N][N];
char str[N],_str[N];

int main(){
    while(~scanf("%s",str)){
        scanf("%s",_str);
        int n=strlen(str);
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        //写法跟lightoj 1422 那个换装类似
        for(int len=1;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                dp[i][j]=dp[i][j-1]+1;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                if(_str[i]==_str[j])
                    dp[i][j]--;
            }
        }
        for(int i=0;i<n;i++){
           ans[i]=dp[0][i];
           if(str[i]==_str[i]){
                if(i==0) ans[0]=0;
                else ans[i]=ans[i-1];
           }
           for(int j=0;j<i;j++)
            ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
        }
        printf("%d\n",ans[n-1]);
    }
	return 0;
}
