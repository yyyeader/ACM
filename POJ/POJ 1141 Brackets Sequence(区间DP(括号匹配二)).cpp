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

int dp[N][N],path[N][N];
char str[N];

void print(int l,int r){
    if(l>=r){
        if(l==r){
            if(str[l]==')'||str[l]=='(')
                printf("()");
            if(str[l]==']'||str[l]=='[')
                printf("[]");
        }
        return;
    }
    if(path[l][r]==-1){
        printf("%c",str[l]);
        print(l+1,r-1);
        printf("%c",str[r]);
    }
    else{
        int k=path[l][r];
        print(l,k);
        print(k+1,r);
    }
}

int main(){
    while(gets(str)){
        memset(path,-1,sizeof(path));
        int n=strlen(str);
        for(int i=0;i<=n;i++){
            dp[i][i]=1;
        }
        for(int len=1;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                dp[i][j]=INF;
                if(str[i]=='('&&str[j]==')'||str[i]=='['&&str[j]==']'){
                    dp[i][j]=dp[i+1][j-1];
                }
                for(int k=i;k<j;k++){
                    if(dp[i][j]>dp[i][k]+dp[k+1][j]){
                        dp[i][j]=dp[i][k]+dp[k+1][j];
                        path[i][j]=k;       //记录分割点
                    }
                }
            }
        }
        print(0,n-1);
        printf("\n");
    }
	return 0;
}
