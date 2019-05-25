#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+5;
char s1[N],s2[N];
int dp[N][N];

int main(){
	while(~scanf("%s%s",s1,s2)){
		memset(dp,0,sizeof(dp));
		int len1=strlen(s1),len2=strlen(s2);
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(s1[i-1]==s2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}
