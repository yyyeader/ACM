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
	FAST_IO;
	LL l,r;
	while(cin>>l>>r){
		LL mmax=0,pos=-1;
		for(int i=0;i<64;i++){
			if((1LL<<i)<=r){
				mmax=(1LL<<i);
				pos=i;
			}
			else
			 break;
		}
		if(l==r){
			cout<<"0"<<endl;
			continue;
		}
		//从最高位开始枚举,枚举到首次mmax-1>=l时结束,如mmax=10000000,mmax-1=01111111或者mmax=11010000,mmax-1=11001111等 
		while(pos>0){
			if(mmax-1>=l)
				break;
			pos--;
			if(mmax+(1LL<<pos)<=r)
				mmax+=(1LL<<pos);
		}
		LL ans=mmax^(mmax-1);
		cout<<ans<<endl;
	}
	return 0;
}

