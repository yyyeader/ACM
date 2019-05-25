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

struct node{
	LL cost,idx,cnt;
	bool operator < (const node b)const{
		return cost==b.cost?idx<b.idx:cost<b.cost;
	}
}a[N];
set<node>st;

int main(){
	LL n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].cnt);
		a[i].idx=i;
	}
	for(int i=1;i<=n;i++) scanf("%lld",&a[i].cost),st.insert(a[i]);
	for(int i=1;i<=m;i++){
		LL sum,kind,ans=0;
		scanf("%lld %lld",&kind,&sum);
		if(a[kind].cnt>=sum) a[kind].cnt-=sum,ans+=a[kind].cost*sum,sum=0;
		else ans+=a[kind].cost*a[kind].cnt,sum-=a[kind].cnt,a[kind].cnt=0;	
		while(sum>0&&st.size()>0){
			auto it=st.begin();
			node t=(*it);	
			if(a[t.idx].cnt>=sum) a[t.idx].cnt-=sum,ans+=a[t.idx].cost*sum,sum=0;
			else ans+=a[t.idx].cost*a[t.idx].cnt,sum-=a[t.idx].cnt,a[t.idx].cnt=0;
			if(a[t.idx].cnt==0) st.erase(it);
		}
		if(sum>0) ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}

