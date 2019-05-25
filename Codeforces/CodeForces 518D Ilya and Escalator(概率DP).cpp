#include<bits/stdc++.h>
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
const int N=2e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

double dp[N][N];//dp[i][j]表示j秒后出队i个人的概率 

int main(){
	int n,t;
	double p;
	scanf("%d%lf%d",&n,&p,&t);
	dp[0][0]=1.0;
	for(int j=1;j<=t;j++){
		for(int i=0;i<=min(n,j);i++){
			if(i==0)
				dp[i][j]=dp[i][j-1]*(1-p);
			else if(i!=n)
				dp[i][j]=dp[i-1][j-1]*p+dp[i][j-1]*(1-p);
			else
				dp[i][j]=dp[i-1][j-1]*p+dp[i][j-1];
		}
	}
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[i][t]*i;
	}
	printf("%.8f\n",ans);
	return 0;
}

