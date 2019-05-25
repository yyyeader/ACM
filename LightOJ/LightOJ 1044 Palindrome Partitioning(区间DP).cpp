#include<stdio.h>
#include<string.h>
const int N=1005;
int dp[N];
char temp[N];

int min(int a,int b){
	return a<b?a:b;
}

bool judge(int l,int r){
	int j=r-1;
	for(int i=l-1;i<j;i++,j--){
		if(temp[i]!=temp[j])
			return false;
	}
	return true;	
}

int main(){ 
	int n,i,j,k,q,cnt;
	scanf("%d",&q);
	for(cnt=1;cnt<=q;cnt++){
		scanf("%s",temp);
		n=strlen(temp);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			dp[i]=i;//用dp[i]表示前i个字符划分成回文串，需要划分成多少个部分 
			for(j=0;j<=i;j++){
				if(judge(j,i)){
					if(j==0)
						dp[i]=1;
					else
						dp[i]=min(dp[i],dp[j-1]+1);//如果j~i回文，那相当于j~i可以看成是1个子集，dp[i]就可以看成dp[j-1]+1; 
				}					
			}
		}	
		printf("Case %d: %d\n",cnt,dp[n]);
	}
}
