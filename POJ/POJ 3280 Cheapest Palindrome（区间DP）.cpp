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
const int N=3e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int add[30],del[30];
int dp[N][N];
char str[N];

int main(){
    FAST_IO;
    int n,m;
    while(cin>>n>>m){
        memset(dp,0,sizeof(dp));
        cin>>str;
        for(int i=1;i<=n;i++){
            char ch;
            int v1,v2;
            cin>>ch>>v1>>v2;
            add[ch-'a']=v1;
            del[ch-'a']=v2;
        }
        for(int len=1;len<m;len++){
            for(int i=0;i+len<m;i++){
                int j=len+i;
                dp[i][j]=INF;
                dp[i][j]=min(dp[i][j],min(add[str[i]-'a'],del[str[i]-'a'])+dp[i+1][j]);
                dp[i][j]=min(dp[i][j],min(add[str[j]-'a'],del[str[j]-'a'])+dp[i][j-1]);
                if(str[i]==str[j]){
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                }
            }
        }
        printf("%d\n",dp[0][m-1]);
    }
	return 0;
}
