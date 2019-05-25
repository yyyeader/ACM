#include <bits/stdc++.h>
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

LL f[105];

int main(){
	f[1]=3,f[2]=f[3]=6;
	for(int i=4;i<100;i++) f[i]=f[i-2]*2+f[i-1];
	int n;
	while(cin>>n){
		cout<<f[n]<<endl;
	}
	return 0;
}

