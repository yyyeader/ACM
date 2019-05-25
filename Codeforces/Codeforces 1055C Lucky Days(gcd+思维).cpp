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

LL cal(LL la,LL ra,LL lb,LL rb){
	return min(ra,rb)-max(la,lb)+1;
}

int main(){
	LL la,ra,lb,rb,ta,tb;
	scanf("%lld%lld%lld%lld%lld%lld",&la,&ra,&ta,&lb,&rb,&tb);
	LL gd=__gcd(ta,tb);
	LL t=abs(la-lb)/gd;
	if(la<lb)
		la+=gd*t,ra+=gd*t;
	else
		lb+=gd*t,rb+=gd*t;
	LL ans=0;
	ans=max(ans,cal(la,ra,lb,rb));
	//因为可能两个区间起点不能完全重合,所以在大一点和小一点两种情况中取最优解 
	if(la<lb)
		la+=gd,ra+=gd;
	else
		lb+=gd,rb+=gd;
	ans=max(ans,cal(la,ra,lb,rb)); 
	printf("%lld\n",ans);
	return 0;
}

