#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=105;
const int S=50;

struct node{
	int x,y;
}a[N][S];

int n;
int sum[N];
double dp[N][S];//dp[i][j]表示从起点走到第i行第j列的最优解 

double cal(node a,node b){
	return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<sum[i];j++){
			dp[i][j]=1e9;
		}
	}
}

int main(){
	FAST_IO;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>sum[i];
			for(int j=0;j<sum[i];j++){
				cin>>a[i][j].x>>a[i][j].y;
			}
		}	

		double ans=1e9;
		//枚举起点 
		for(int i=0;i<sum[0];i++){
			//注意每次枚举起点都要初始化 
			init();
			for(int j=1;j<n;j++){
				if(j==1){
					for(int k=0;k<sum[j];k++){
						dp[j][k]=cal(a[0][i],a[j][k]);
					}
					continue;
				}
				
				for(int k=0;k<sum[j];k++){
					for(int p=0;p<sum[j-1];p++){
						dp[j][k]=min(dp[j][k],dp[j-1][p]+cal(a[j][k],a[j-1][p]));
					}
				}
			}
			for(int k=0;k<sum[n-1];k++){
				dp[n-1][k]=dp[n-1][k]+cal(a[n-1][k],a[0][i]);
				ans=min(ans,dp[n-1][k]);
			}
		}
		cout<<int(ans*100)<<endl;
	}
	return 0;
}

