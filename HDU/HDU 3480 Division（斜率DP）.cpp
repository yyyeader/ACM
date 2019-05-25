#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1e4+5;

int head,tail;
int dp[N][5005],a[N],q[N];

int getUP(int m,int k,int j){
	return dp[k][j-1]+a[k+1]*a[k+1]-dp[m][j-1]-a[m+1]*a[m+1];
}

int getDOWN(int m,int k){
	return 2*(a[k+1]-a[m+1]);
}

//dp[i][j]=min{dp[k][j-1]+(a[i]-a[k+1])^2}
int getDP(int i,int j,int k){
	return dp[k][j-1]+(a[i]-a[k+1])*(a[i]-a[k+1]);
}

int main(){
	int t,cas=0;
	scanf("%d",&t);
	int cnt=0;
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			dp[i][1]=(a[i]-a[1])*(a[i]-a[1]);
		}
		
		for(int j=2;j<=m;j++){
			head=tail=0;
			q[tail++]=j-1;
			for(int i=j;i<=n;i++){
				cnt++;
				while(head+1<tail&&getUP(q[head],q[head+1],j)<=a[i]*getDOWN(q[head],q[head+1])){
					head++;
				}
				dp[i][j]=getDP(i,j,q[head]);
				while(head+1<tail&&getUP(q[tail-1],i,j)*getDOWN(q[tail-2],q[tail-1])<=getUP(q[tail-2],q[tail-1],j)*getDOWN(q[tail-1],i)){
					tail--;
				}
				q[tail++]=i;
			}
		}
		printf("Case %d: %d\n",++cas,dp[n][m]);
	}
	return 0;
}


