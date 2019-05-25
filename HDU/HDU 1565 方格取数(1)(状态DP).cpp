#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=25;
const int M=18000;

int n;
int dp[N][M],mp[N][N],sta[M];//dp[i][j]��ʾ�ڵ�i�У�״̬jʱ������ֵ

//���һ�е����п���״̬ 
int dfs(){
	int lim=(1<<n);
	int sum=0;
	for(int i=0;i<lim;i++){
		if(i&(i<<1))
			continue;
		sta[sum++]=i;
	}
	return sum;
}

//�����Ӧ״̬�ļ�ֵ	
int cal(int row,int x){
	int val=0;
	for(int i=0;i<n;i++){
		int tmp=(1<<i);
		if(tmp&x){
			val+=mp[row][n-i-1];
		}
	}
	return val;
}

int main(){
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>mp[i][j];
			}
		}
		int sum=dfs();
		for(int i=0;i<n;i++){
			if(i==0){
				for(int j=0;j<sum;j++){
					dp[i][j]=cal(i,sta[j]);
				}
				continue;
			}
			//ö�ٵ�ǰ��״̬ 
			for(int j=0;j<sum;j++){
				int val=cal(i,sta[j]);
				//ö����һ��״̬ 
				for(int k=0;k<sum;k++){
					//��������û�����ڵĸ��� 
					if(sta[j]&(sta[k])) continue;
					//ע��dp[i][j]����dp[i][sta[j]]��Ϊsta[j]�ᳬ�����С 
					dp[i][j]=max(dp[i][j],dp[i-1][k]+val);
				}
			}
		}
		int ans=0;
		for(int i=0;i<sum;i++){
			ans=max(ans,dp[n-1][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

