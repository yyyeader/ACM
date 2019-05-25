#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=5e5+5;
const long long INF=4e18;

int n,d,k;
LL dis[N],score[N],dp[N],q[N];

bool judge(int i,int j,int g){
	if(dis[i]-dis[j]<=g+d&&dis[i]-dis[j]>=max(d-g,1))
		return true;
	return false;
}

bool check(int g){
	//错误：默认了0可以到达第一个点 
	int head=0,tail=0,cur=0,qmin=max(d-g,1),qmax=d+g;
	q[tail++]=0;
	for(int i=1;i<=n;i++){
		while(head+1<tail&&dis[i]-dis[q[head]]>qmax){
			head++;
		}
		if(judge(i,q[head],g))
			dp[i]=dp[q[head]]+score[i];
		else
			dp[i]=-INF;
		if(dp[i]>=k)
			return true;
		while(cur<=i&&dis[i+1]-dis[cur]>=qmin){
			//能到达q[tail-1]的肯定能到达cur点，且dp[cur]价值较大，所以q[tail-1]点可以舍去 
			while(head+1<=tail&&dp[q[tail-1]]<=dp[cur]){
				tail--;
			}
			q[tail++]=cur++;
		}
	}
	return false;
}

int main(){	
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&dis[i],&score[i]);
	}
	int l=0,r=1e9,cost=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			if(cost==-1||cost>mid)
				cost=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	printf("%d\n",cost);
	return 0;
}
