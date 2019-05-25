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
const int N=5e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int a[N],dp1[N],dp2[N];
//dp1[i]表示从左往右以i为结尾的连续不降子序列长度 
//dp1[i]表示从右往左以i为结尾的连续不降子序列长度 

int main(){
	FAST_IO;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp1[i]=dp2[i]=1;
	}
	for(int i=2;i<=n;i++){
		if(a[i-1]>=a[i])
			dp1[i]+=dp1[i-1];
	}
	for(int i=n-1;i>=1;i--){
		if(a[i+1]>=a[i])
			dp2[i]+=dp2[i+1];
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		int len=r-l+1;
		if(dp1[r]+dp2[l]>=len+1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

