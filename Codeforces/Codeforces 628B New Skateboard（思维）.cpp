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
	FAST_IO;
	string str;
	cin>>str;
	int sze=str.size();
	LL ans=0;
	for(int i=sze-1;i>=0;i--){
		int num=str[i]-'0';
		if(num%4==0)
			ans++;
		if(i>0){
			int t=num+(str[i-1]-'0')*10;
			if(t%4==0)
				ans+=i;			//若s[i]*10+s[i-1] 能被4整除那么数字左边无论加什么都会被4整除 
		}
	}
	cout<<ans<<endl;
	return 0;
}

