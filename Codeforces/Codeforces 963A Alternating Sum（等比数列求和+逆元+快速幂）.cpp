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
const LL MOD=1e9+9;
const double eps=1e-10;

string str;

LL fpow(LL x,LL n){
	LL res=1;
	while(n>0){
		if(n&1) res=res*x%MOD;  //如果二进制最低位为1，则乘上x^(2^i)
		x=x*x%MOD;	            //将x平方并取模
		n>>=1;
	}
	return (res%MOD+MOD)%MOD;
}

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
    LL n,a,b,k;
    cin>>n>>a>>b>>k;
    cin>>str;
    LL len=(n+1)/k;
    LL sum=0;
    for(int i=0;i<k;i++){
        if(str[i]=='+')
            sum=((sum+fpow(a,n-i)*fpow(b,i))%MOD+MOD)%MOD;
        else
            sum=((sum-fpow(a,n-i)*fpow(b,i))%MOD+MOD)%MOD;
    }
    LL ans;
    //注意，比值q是(b/a)^k而不是(b/a)
    LL q=fpow(NY(a),k)*fpow(b,k)%MOD;
    if(q!=1){
        LL _q=NY(q-1);
        ans=(sum*(fpow(q,len)-1)%MOD*_q%MOD+MOD)%MOD;
    }
    else
        ans=sum*len%MOD;
    cout<<ans<<endl;
	return 0;
}
