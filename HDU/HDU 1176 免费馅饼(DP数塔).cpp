#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005;
int dp[15][N];

int main(){
	//freopen("in.txt","r",stdin);
	int i,j,n,pos,time,ans,limit;
	while(scanf("%d",&n)&&n){
		memset(dp,0,sizeof(dp));
		limit=ans=0;
		while(n--){
			scanf("%d %d",&pos,&time);
			dp[pos+1][time]++;//空出边界,将位置向右移一位 
			if(time>limit)
				limit=time;
		}	
		for(j=limit-1;j>=0;j--){
			for(i=1;i<=11;i++){
				dp[i][j]+=max(dp[i][j+1],max(dp[i-1][j+1],dp[i+1][j+1]));
			}
		} 
		printf("%d\n",dp[6][0]);
	}
} 
