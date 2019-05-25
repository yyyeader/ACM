#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1e6+5;
const LL inf=1e18;

LL a[N],dp[N],pre[N];

int main(){
	int m,n;
	while(~scanf("%d%d",&m,&n)){
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		LL tmp;
		for(int i=1;i<=m;i++){
			tmp=-inf;
			for(int j=i;j<=n;j++){
				dp[j]=max(dp[j-1]+a[j],pre[j-1]+a[j]);
				pre[j-1]=tmp;
				tmp=max(tmp,dp[j]);
			}
		}	
		printf("%lld\n",tmp);
	}
	return 0;
} 
