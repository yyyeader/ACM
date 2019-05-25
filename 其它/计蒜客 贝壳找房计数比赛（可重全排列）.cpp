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
const LL MOD=1e9+7; 
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL mp[300];

LL extend_gcd(LL a,LL b,LL &x,LL &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    LL gcd=extend_gcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-(a/b)*x;
    return gcd;
}

LL NY(LL num){
    LL x,y;
    extend_gcd(num,MOD,x,y);
    return (x%MOD+MOD)%MOD;
}

int main(){
	FAST_IO;
	int T;
	cin>>T;
	while(T--){
		memset(mp,0,sizeof(mp));
		string s,t;
		cin>>s>>t;
		for(int i=0;i<s.length();i++){
			mp[s[i]]++;
		}
		bool flag=true;
		for(int i=0;i<t.length();i++){
			if(mp[t[i]]>0)
				mp[t[i]]--;
			else
				flag=false;
		}
		if(!flag){
			cout<<0<<endl;
			continue;
		}
		LL ans=1;
		LL len=s.length()-t.length();
		for(int i=1;i<=len;i++){
			ans=ans*i%MOD;
		}
		LL sum=1;
		for(int i='a';i<='z';i++){	
			for(int j=1;j<=mp[i];j++){
				sum=sum*j%MOD;
			}
		}
		ans=ans*NY(sum)%MOD;
		cout<<ans*(len+1)%MOD<<endl;
	}
	return 0;
}

