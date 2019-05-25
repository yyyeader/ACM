#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=25;
const int INF=0x3f3f3f3f;

int n,m,ans;
int dp[N][N];//dp[i][j]��ʾȡ��iΪֹ,��j���˵�״̬ 
stack<int>res;

void dfs(int x){
	if(res.size()>=ans) return;
	if(x==n){
		rep(i,0,n-1){
			if(dp[x][i]!=(1<<n)-1)
				return;
		}
		ans=res.size();
		return;
	}
	memcpy(dp[x+1],dp[x],sizeof(dp[x]));
	//ȡ��x���� 
	dfs(x+1);
	//��ȡ��x���� 
	rep(i,0,n-1){
		//����i���˺͵�x����ʶ�����i������ʶ���е�x������ʶ���� 
		if(dp[x][x]&(1<<i))
			dp[x+1][i]|=dp[x][x];
	}
	res.push(x+1);
	dfs(x+1);
	res.pop();
}

int main(){
	FAST_IO;
	cin>>n>>m;
	rep(i,1,n)	dp[0][i-1]=1<<i-1;
	rep(i,1,m){
		int a,b;
		cin>>a>>b;
		a--,b--;
		dp[0][a]|=1<<b;
		dp[0][b]|=1<<a;
	}
	ans=INF;
	dfs(0);
	cout<<ans<<endl;
	return 0;
}

