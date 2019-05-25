#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
typedef long long LL;
const int N=1e3+5;
const int MAX=1e5+5;

LL dp[15][N];
LL a[MAX],b[MAX],p[N],k[N];

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<=10;i++)
            for(int j=1;j<=1000;j++)
                dp[i][j]=1e18;
        LL max1=0,max2=0;
        for(int i=1;i<=n;i++){
        	scanf("%I64d%I64d",&a[i],&b[i]);
        	max1=max(max1,b[i]);
		}    
        for(int i=1;i<=m;i++){
        	scanf("%I64d%I64d",&k[i],&p[i]);
        	max2=max(max2,p[i]);
		}
        if(max1>=max2){
        	printf("-1\n");
        	continue;
		}
		
        for(int d=0;d<=10;d++){
            for(int j=1;j<=m;j++){
                if(p[j]>d){
                    for(int i=1;i<=1000;i++){
                        LL att=p[j]-d;//一次攻击造成的伤害
                        if(i<=att)
                            dp[d][i]=min(dp[d][i],k[j]);
                        else
                            dp[d][i]=min(dp[d][i],dp[d][i-att]+k[j]);
                    }
                }
            }
        }
		
        long long sum=0;
        for(int i=1;i<=n;i++){
            sum+=dp[b[i]][a[i]];
        }
        printf("%I64d\n",sum) ;
    }
}
