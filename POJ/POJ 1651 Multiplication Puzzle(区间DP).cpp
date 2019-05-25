#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=205;
const LL INF=1e18;
LL a[N],dp[N][N];

int main(){
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int len=2;len<n;len++){
            for(int i=1;i+len<=n;i++){
                int j=i+len;
                dp[i][j]=INF;
                //枚举删除[i+1,j-1]内的数
                for(int k=i;k<j-1;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k+1]+dp[k+1][j]+a[i]*a[k+1]*a[j]);
                }
            }
        }
        cout<<dp[1][n]<<endl;
    }
    return 0;
}
