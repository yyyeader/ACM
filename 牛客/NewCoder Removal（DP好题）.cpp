#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=1e5+5;
const int M=15;
const LL MOD=1e9+7;

int dp[N][M];//dp[i][j]��ʾ����Ϊi����ĩβ������Ϊj�������з����� 
int sum[N];  //sum[i]������Ϊi�������и��� 

int main(){
	FAST_IO;
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k)){
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		sum[0]=1;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			for(int j=i;j>=max(1,i-m);j--){
				//����һ��,ÿ�ζ��һ������x����ôx���Ը�sum[j-1]��ÿһ�������ж���ɳ���Ϊj�������У�����sum[j]+=sum[j-1]
				//Ȼ�����ظ����ټ�ȥ���е���xΪ��β����Ϊj�������У���sum[j]+=sum[j-1]-dp[j][x]
				sum[j]=(sum[j]+sum[j-1]-dp[j][x]+MOD)%MOD;
				dp[j][x]=sum[j-1];
			}
		}
		printf("%d\n",sum[n-m]);
	}
	return 0;
}

