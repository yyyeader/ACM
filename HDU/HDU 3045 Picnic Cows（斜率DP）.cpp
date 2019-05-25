#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
const int N=5e5+5;

int head,tail;
LL sum[N],dp[N],a[N],q[N];;

LL getUP(int k,int j){
	return dp[j]+a[j+1]*(j+1)-sum[j+1]-dp[k]-a[k+1]*(k+1)+sum[k+1];
}

LL getDOWN(int k,int j){
	return a[j+1]-a[k+1];
}

//dp[i]=min{dp[j]+sum[i]-sum[j+1]-a[j+1]*(i-j-1)}
LL getDP(int i,int j){
	return dp[j]+sum[i]-sum[j+1]-a[j+1]*(i-j-1);
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		memset(dp,0x3f3f3f3f,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		dp[0]=0;
		head=tail=0;
		q[tail++]=0;
		for(int i=1;i<=n;i++){
			while(head+1<tail&&getUP(q[head],q[head+1])<=i*getDOWN(q[head],q[head+1])){
				head++;
			}
			dp[i]=getDP(i,q[head]);
			int j=i-m+1;
			//注意z这个判断,因为状态转移,也就是分组,至少要保证第一组有m头牛。 
			if(j<m)
				continue;
			while(head+1<tail&&getUP(q[tail-1],j)*getDOWN(q[tail-2],q[tail-1])<=getUP(q[tail-2],q[tail-1])*getDOWN(q[tail-1],j)){
				tail--;
			}
			q[tail++]=j;
		}
		printf("%lld\n",dp[n]);
	}

	return 0;
}
