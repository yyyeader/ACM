#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=1e2+5;
const LL INF=1e18;
const double eps=1e-10;

int col[N];
LL cost[N][N];
LL dp[N][N][N];//dp[i][j][k]表示在位置i,已有j团颜色,所刷颜色为k时的最小花费 

int main(){
	FAST_IO;
	int n;
	while(cin>>n){
		int m,lim;
		cin>>m>>lim;
		for(int i=1;i<=n;i++){
			cin>>col[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>cost[i][j];
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				for(int k=0;k<N;k++){
					dp[i][j][k]=INF;
				}
			}
		}
		memset(dp,0x3f,sizeof(dp));
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++){
			//已有颜色 
			if(col[i]!=0){
				int p=col[i];
				for(int j=1;j<=lim;j++){
					for(int k=0;k<=m;k++){
						if(p==k){
							dp[i][j][p]=min(dp[i][j][p],dp[i-1][j][k]);
						}
						else{
							dp[i][j][p]=min(dp[i][j][p],dp[i-1][j-1][k]); 
						}
					}
				}
				continue;
			}
			//没有颜色 
			for(int j=1;j<=lim;j++){
				for(int k=0;k<=m;k++){
					if(dp[i-1][j][k]==INF&&dp[i][j][k]==INF) continue;
					for(int p=1;p<=m;p++){
						if(p==k){
							dp[i][j][p]=min(dp[i][j][p],dp[i-1][j][k]+cost[i][p]);
						}
						else{
							dp[i][j][p]=min(dp[i][j][p],dp[i-1][j-1][k]+cost[i][p]); 
						}
					}
				}
			}
		}
		LL ans=INF;
		for(int i=1;i<=m;i++){ 
			ans=min(ans,dp[n][lim][i]);
		} 
		if(ans!=INF)
			cout<<ans<<endl;
		else
			cout<<"-1"<<endl;
		
	}
	return 0;
}

