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
const int N=1e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

vector<int>fat[N];
int a[N],d[N],dp[N];

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=a[n];i++){
		for(int j=i;j<=a[n];j+=i){
			fat[j].push_back(i);
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		//遍历因子 
		for(int j=0;j<fat[a[i]].size();j++){
			int t=fat[a[i]][j];
			dp[i]=max(dp[i],d[t]+1);
		}
		for(int j=0;j<fat[a[i]].size();j++){
			int t=fat[a[i]][j];
			d[t]=dp[i];
		}
		ans=max(ans,dp[i]);
	}
	//只有1的时候ans为0，实际为1 
	cout<<max(ans,1)<<endl;
	return 0;
}
