#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e4+5;

long long dp[N];

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		int sum=(1+n)*n/2;
		if(sum%2==1)
			puts("0");
		else{
			sum/=2;
			dp[0]=1;
			for(int i=1;i<=n;i++){
				for(int j=sum;j>=0;j--){
					if(j>=i)
						dp[j]+=dp[j-i];
				}
			}
			printf("%lld\n",dp[sum]/2);
		}
	} 
	return 0;
}
