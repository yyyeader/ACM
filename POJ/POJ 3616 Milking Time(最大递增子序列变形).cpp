#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;
const int N=1e3+5;

struct node{
	int start,end,val;
}a[N];

bool cmp(node a,node b){
	return a.start<b.start;
}

int dp[N];

int main(){
	int n,m,r;
	while(~scanf("%d%d%d",&n,&m,&r)){
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&a[i].start,&a[i].end,&a[i].val);
		sort(a+1,a+1+m,cmp);
		
		int ans=0;
		//不重合的最大递增区间，类似最大递增子序列 
		for(int i=1;i<=m;i++){
			dp[i]=a[i].val;
			for(int j=1;j<i;j++){
				if(a[j].end+r<=a[i].start){
					dp[i]=max(dp[i],dp[j]+a[i].val);
				}				
			}
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
