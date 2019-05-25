#include<bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const LL MOD=1e9+7;
const double eps=1e-10;

int a[N];//a[i]表示剩余涂色次数为i的颜色种类 
LL dp[16][16][16][16][16][5];
//ai表示剩余涂色次数为i的颜色数,last表示最后一次使用的颜色剩余涂色次数为last
LL dfs(int a1,int a2,int a3,int a4,int a5,int last){
	if(dp[a1][a2][a3][a4][a5][last]!=-1) return dp[a1][a2][a3][a4][a5][last];
	if(!(a1||a2||a3||a4||a5)){
		return 1;
	}
	LL ans=0;
	//如果上次填的是颜色剩余次数为2的，意味着颜色中剩余次数为1的多了一个，
	//那么这一次并不能再选这种颜色，这次可以选填1的就要少1。
	if(a1)	ans+=(a1-(last==2))*dfs(a1-1,a2,a3,a4,a5,1);
	if(a2)	ans+=(a2-(last==3))*dfs(a1+1,a2-1,a3,a4,a5,2);
	if(a3)	ans+=(a3-(last==4))*dfs(a1,a2+1,a3-1,a4,a5,3);
	if(a4)	ans+=(a4-(last==5))*dfs(a1,a2,a3+1,a4-1,a5,4);
	if(a5)	ans+=a5*dfs(a1,a2,a3,a4+1,a5-1,5);
	return dp[a1][a2][a3][a4][a5][last]=ans%MOD;
}

int main(){	
	FAST_IO;
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		a[num]++;
	}
	cout<<dfs(a[1],a[2],a[3],a[4],a[5],0)<<endl;
	return 0;
}

