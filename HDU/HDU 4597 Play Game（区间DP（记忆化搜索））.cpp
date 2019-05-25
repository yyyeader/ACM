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
#define fin(name)  freopen(name,"r1",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=25;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int a[N],b[N];
int dp[N][N][N][N];

int solve(int l1,int r1,int l2,int r2){
	if(dp[l1][r1][l2][r2]!=-1)
		return dp[l1][r1][l2][r2];
		
	int ans=0,sum=0;
	if(l1<=r1)
		sum+=a[r1]-a[l1-1]; 
	if(l2<=r2)
		sum+=b[r2]-b[l2-1];
	//从子区间推过来相当于先后手顺序发生了改变，所以用减相当于取反
	if(l1<=r1){
		ans=max(ans,sum-solve(l1+1,r1,l2,r2));
		ans=max(ans,sum-solve(l1,r1-1,l2,r2));
	}
	if(l2<=r2){
		ans=max(ans,sum-solve(l1,r1,l2+1,r2));
		ans=max(ans,sum-solve(l1,r1,l2,r2-1));
	}
	
	return dp[l1][r1][l2][r2]=ans;
}

int main(){
	FAST_IO;
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		int n;
		scanf("%d",&n);
		_for(i,1,n){
			cin>>a[i];
			a[i]+=a[i-1];
		}
		_for(i,1,n){
			cin>>b[i];
			b[i]+=b[i-1];
		}
		printf("%d\n",solve(1,n,1,n));
	}
	return 0;
}
