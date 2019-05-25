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

int main(){
	int n,k;
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=2*n;i+=2){
		if(cnt<k)
			cout<<i+1<<" "<<i<<" ";
		else
			cout<<i<<" "<<i+1<<" ";
		cnt++;
	}
	return 0;
}

