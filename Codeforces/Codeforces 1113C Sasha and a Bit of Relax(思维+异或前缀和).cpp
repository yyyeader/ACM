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

LL sum[(1<<20)+10][2];

int main(){
	FAST_IO;
	int n,xsum=0;
	sum[0][0]=1;
	LL ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		xsum^=x;
		ans+=sum[xsum][i%2];
		sum[xsum][i%2]++;
	}
	cout<<ans<<endl;
	return 0;
}

