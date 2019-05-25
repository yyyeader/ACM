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
const int N=2e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int l[N],r[N],a[N],ans[N];
stack<int>sk;

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(!sk.empty()&&a[sk.top()]>=a[i]) 
			sk.pop();
		if(!sk.empty())
			l[i]=sk.top();
		else
			l[i]=0;
		sk.push(i);
	}
	while(!sk.empty()) sk.pop();
	for(int i=n;i>=1;i--){
		while(!sk.empty()&&a[sk.top()]>=a[i])
			sk.pop();
		if(!sk.empty())
			r[i]=sk.top();
		else
			r[i]=n+1;
		sk.push(i);
	}
	for(int i=1;i<=n;i++){
		int len=r[i]-l[i]-1;
		ans[len]=max(a[i],ans[len]);
	}
	for(int i=n-1;i>=1;i--){
		ans[i]=max(ans[i],ans[i+1]);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

