#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+5;

struct node{
	int val,weight;
}a[N*2];

int dp[N];

int main(){
	int n,m,v;
	while(~scanf("%d%d%d",&v,&n,&m)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n+m;i++)
			scanf("%d",&a[i].val);
		for(int i=1;i<=n+m;i++)
			scanf("%d",&a[i].weight);
		
		for(int i=1;i<=n;i++)
			for(int j=v;j>=a[i].weight;j--)
				dp[j]=max(dp[j],dp[j-a[i].weight]+a[i].val);
		for(int i=n+1;i<=n+m;i++)
			for(int j=a[i].weight;j<=v;j++)
				dp[j]=max(dp[j],dp[j-a[i].weight]+a[i].val);
		printf("%d\n",dp[v]);
	}
	return 0;
}
