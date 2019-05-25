#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

vector<LL>prime;
LL num[N];

int main(){
	LL n,b;
	cin>>n>>b;
	
	//分解质因子
	for(LL i=2;i*i<=b;i++){
		if(b%i==0){
			prime.push_back(i);
			while(b%i==0){
				b/=i;
				num[prime.size()-1]++;
			}
		}
	}
	if(b!=1){
		prime.push_back(b);
		num[prime.size()-1]++;
	}
	//n!下p的幂 = [ n/p ] + [ n/(p^2) ] + [ n/(p^3) ] ...
	LL mmin=(1LL<<62);
	for(int i=0;i<prime.size();i++){
		LL sum=0,p=prime[i],mul=1;
		while(mul<=n/p){
			mul*=p;
			sum+=n/mul;
		}
//		cout<<sum<<" "<<p<<endl;
		mmin=min(mmin,sum/num[i]);
	}
	cout<<mmin<<endl;
	return 0;
}

