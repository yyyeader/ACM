#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std; 
const int N=1e4+5;

int w[N];//w[i]表示强银行i能获得的金钱 
double dp[N],v[N];//dp[i]表示抢劫i元不被抓的最大概率,v[i]表示强银行i被抓概率 

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		double lim;
		cin>>lim>>n;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>w[i]>>v[i];
			sum+=w[i];
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=sum;j>=w[i];j--){
				dp[j]=max(dp[j],dp[j-w[i]]*(1-v[i]));
			}
		}
		int ans=0;
		for(int i=sum;i>=0;i--){
			if(1-dp[i]<=lim){
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
