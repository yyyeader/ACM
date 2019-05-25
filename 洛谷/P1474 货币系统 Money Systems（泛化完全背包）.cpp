#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e4+5;

int a[105];
long long dp[N];

int main(){
	int n,v;
	while(~scanf("%d%d",&n,&v)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=v;j++){
				if(j>=a[i]&&dp[j-a[i]])
					dp[j]+=dp[j-a[i]];
			}
		}
		printf("%lld\n",dp[v]);
	}
	return 0;
}



