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
const int N=5e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int n;
int a[N],b[N],dp[N],sign[N];

bool check(int x){
	memset(sign,-1,sizeof(sign));
	for(int i=1;i<=n;i++){
		if(a[i]-x<=0)
			sign[i]=x-a[i];
	}
	for(int i=1;i<=n;i++){
		if(sign[i]<sign[i-1])
			sign[i]=sign[i-1]-1;
	}
	for(int i=n;i>=1;i--){
		if(sign[i]<sign[i+1])
			sign[i]=sign[i+1]-1;
	}
	
	bool flag=true;
	for(int i=x+1;i<=n-x;i++){
		if(sign[i-1]>0)
			dp[i]=0;
		else
			dp[i]=min(a[i],a[i-1]+1);
	}
	for(int i=n-x;i>=x+1;i--){
		if(sign[i+1]>0)
			dp[i]=0;
		else
			dp[i]=min(a[i+1]+1,dp[i]);
	}
	for(int i=x+1;i<=n-x;i++){
		if(dp[i]-x>0) flag=false;
	}
	return flag;
}

int main(){
	FAST_IO;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r)	{
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}

