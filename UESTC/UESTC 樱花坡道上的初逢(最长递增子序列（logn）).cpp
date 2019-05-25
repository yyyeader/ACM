#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<cctype>
#include<math.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
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
const LL INF64=1e18;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int a[N],b[N];

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>b[cnt])
			b[++cnt]=a[i];
		else{
			int pos=lower_bound(b+1,b+1+cnt,a[i])-b;
			b[pos]=a[i];
		}
	}
	cout<<cnt<<endl;
	return 0;
}
