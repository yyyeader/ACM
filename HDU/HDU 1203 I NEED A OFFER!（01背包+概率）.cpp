#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int w[N];//w[i]表示第i所学校报名所需学费 
double dp[N],v[N];//dp[i]表示花了i元报名最小失败率,v[i]表示第i所学校报名录取率 

int main(){
	int sum,n;
	while(~scanf("%d%d",&sum,&n)&&(n||sum)){
		for(int i=0;i<=sum;i++){
			dp[i]=1;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%lf",&w[i],&v[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=sum;j>=w[i];j--){
				dp[j]=min(dp[j],dp[j-w[i]]*(1-v[i]));
			}
		}
		printf("%.1f%%\n",(1-dp[sum])*100);
	}
	return 0;
}
