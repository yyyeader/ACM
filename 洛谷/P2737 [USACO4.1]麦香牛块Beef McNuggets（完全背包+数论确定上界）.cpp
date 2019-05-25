#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+5;

int a[105];
long long dp[N];

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=256*256;j++){
				if(j>=a[i])
					dp[j]+=dp[j-a[i]];
			}
		}
		int ans=0;
		for(int i=1;i<=256*256;i++){
			if(dp[i]==0)
				ans=i;
		}
		if(ans>256*256-2*256)
			ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
