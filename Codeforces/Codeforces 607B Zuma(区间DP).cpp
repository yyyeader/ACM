#include<iostream>
#include<cstring>
using namespace std;
const int N=505;
const int INF=0x3f3f3f3f;
int a[N];
int dp[N][N];	//将dp[i][j]删除最少需要的操作数 

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=1;
	}
	for(int d=1;d<n;d++){
		for(int i=1;i+d<=n;i++){
			int j=i+d;
			dp[i][j]=INF;
			if(a[i]==a[j])
				dp[i][j]=max(dp[i+1][j-1],1);
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
