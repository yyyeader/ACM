#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=5e4+5;

LL l,C;
LL sum[N],dp[N],q[N];

//yj-yk/xj-xk
double Slope(int k,int j){
	return double(dp[j]+(sum[j]+C)*(sum[j]+C)-dp[k]-(sum[k]+C)*(sum[k]+C))/(2*sum[j]-2*sum[k]);
}

//dp[i]=min{dp[j]+(sum[i]-sum[j]+i-j-1-l)^2}
LL getDP(int i,int j){
	return dp[j]+(sum[i]-sum[j]-C)*(sum[i]-sum[j]-C);
}

int main(){
	int n;
	scanf("%d%lld",&n,&l);
	C=l+1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&sum[i]);
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=n;i++){
		sum[i]+=i;
	}
	dp[0]=0;
	int head=0,tail=0;
	q[tail++]=0;
	for(int i=1;i<=n;i++){
		while(head+1<tail&&Slope(q[head],q[head+1])<=sum[i]){
			head++;
		}
		dp[i]=getDP(i,q[head]);
		while(head+1<tail&&Slope(q[tail-1],i)<=Slope(q[tail-2],q[tail-1])){
			tail--;
		}
		q[tail++]=i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}
