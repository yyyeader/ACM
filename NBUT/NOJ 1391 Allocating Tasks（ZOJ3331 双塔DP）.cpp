#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=105;
const int INF=0x3f3f3f3f;
int dp[N][N*2];

int main(){
	FAST_IO;
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		memset(dp,0x3f,sizeof(dp));
		dp[0][N]=0;
		for(int i=1;i<=n;i++){
			int ta,tb;
			cin>>ta>>tb;
			for(int j=-99;j<=99;j++){
				if(dp[i-1][j+N]==INF) continue;
				//A塔比B塔低
				if(j<0){
					//放在B塔
					dp[i][-tb+N]=min(dp[i][-tb+N],dp[i-1][j+N]+tb);
					//放在A塔
					dp[i][j+ta+N]=min(dp[i][j+ta+N],dp[i-1][j+N]+(j+ta<0?0:j+ta));
				}
				else{//同理 
					//放在A塔
					dp[i][ta+N]=min(dp[i][ta+N],dp[i-1][j+N]+ta);
					//放在B塔 
					dp[i][j-tb+N]=min(dp[i][j-tb+N],dp[i-1][j+N]+(j-tb>0?0:tb-j));
				}
			}
		}
		int ans=INF;
		for(int i=-99;i<=99;i++){
			ans=min(ans,dp[n][i+N]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
