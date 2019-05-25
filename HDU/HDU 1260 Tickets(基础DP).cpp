#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e3+5;
int s[N],a[N],dp[N];

int main(){
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(int i=2;i<=n;i++)
			scanf("%d",&a[i]);
		dp[1]=s[1];
		for(int i=2;i<=n;i++){
			dp[i]=min(dp[i-1]+s[i],dp[i-2]+a[i]);
		}
		int hour=8,minute=0,sec=0;
		hour=(hour+dp[n]/3600)%24;
     	minute=dp[n]%3600/60;
      	sec=dp[n]%60;
		if(hour<=12)
			printf("%02d:%02d:%02d am\n",hour,minute,sec);
		else
			printf("%02d:%02d:%02d pm\n",hour,minute,sec);
	}
	return 0;
}
