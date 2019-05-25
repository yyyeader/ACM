#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=1e5+5;

LL dp[N];

//f(n)=(n-1)*f(n-2)+g(n)
//g(n)=(n-1)*g(n-1)+(n-1)*(n-2)*f(n-3)/2
int main(){
	int n,MOD;
	while(~scanf("%d%d",&n,&MOD)){
		dp[0]=1;
		LL sum=0;
		for(int i=1;i<=n;i++){
			if(i>=2)
				dp[i]=(i-1)*dp[i-2];
			else 
				dp[i]=0;
			sum=(i-1)*sum;
			if(i>=3)
				sum=(sum+1LL*(i-1)*(i-2)/2*dp[i-3])%MOD;
			dp[i]=(dp[i]+sum)%MOD;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}

