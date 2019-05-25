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

int a[105];

int main(){
	FAST_IO;
	int w,m;
	cin>>w>>m;
	int cnt=0;
	while(m){
		a[cnt++]=m%w;
		m/=w;
	}
	bool flag=true;
	for(int i=0;i<105;i++){
		if(a[i]>=w){
			a[i+1]+=a[i]/w;
			a[i]%=w;
		}
		if(a[i]!=0){
			if(a[i]==w-1)
				a[i+1]++;
			else if(a[i]==1)
				;
			else{
				flag=false;
				break;
			}
		}
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

