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
const int N=1e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int a[N];
bool dp[1005][1005];//dp[i][j]表示是存在前1~i个数的子序和sum使得sum%m=j 

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n>=m){
		puts("YES");
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			dp[i][a[i]%m]=true;
			for(int j=0;j<=m;j++){
				if(dp[i-1][j]){
					dp[i][j]=dp[i][(j+a[i])%m]=true;
				}
			}
		}
		bool flag=dp[n][0];
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
