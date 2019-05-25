#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[25];
int dp[25][25];//dp[i][j]��ʾ�Ѿ�װ��i������,��ռ���˵�i�����̵�����Ϊjʱ�����Ž� 

int main(){
	int n,t,m;
	while(cin>>n>>t>>m) {
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				for(int k=t;k>=a[i];k--){
					//dp[j-1][t]+1    ��CD����һ���´����� 
					//dp[j][k-a[i]]+1 һ�����̷Ŷ���CD 
					//dp[j][k]        ��Ҫ����CD 
					dp[j][k]=max(dp[j][k],max(dp[j-1][t]+1,dp[j][k-a[i]]+1));
				}
			}
		}
		printf("%d\n",dp[m][t]);
	}
	return 0;
}
