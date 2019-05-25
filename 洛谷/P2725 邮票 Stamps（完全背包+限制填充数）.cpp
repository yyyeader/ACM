#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e6+5;

int a[60],dp[N],cnt[N];

int main(){
	int k,n;
	while(~scanf("%d%d",&k,&n)){
		memset(dp,0,sizeof(dp));
		memset(cnt,0x3f,sizeof(cnt));
		dp[0]=1;
		cnt[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=N;j++){
				if(j>=a[i]&&dp[j-a[i]]){
					dp[j]=1;
					cnt[j]=min(cnt[j],cnt[j-a[i]]+1);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=N;i++){
			if(cnt[i]>k||dp[i]==0)
				break;
			ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
