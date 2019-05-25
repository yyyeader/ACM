#include<iostream>
#include<cstdio>
#include<algorithm>
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
const int N=3e4+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int l,r;
	bool operator <(const node &b)const{
		return l<b.l;
	}
}a[N];



int main(){
	int n,t;
	while(~scanf("%d%d",&n,&t)){
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
		sort(a+1,a+1+n);
		int en=0,idx=1,ans=0;
		while(idx<=n&&en<t){
			int mx=-1;
			while(a[idx].l<=en+1) mx=max(mx,a[idx++].r);
			if(mx!=-1)
				en=mx,ans++;
			else break;
		}
		if(en!=t)
			puts("-1");
		else
			printf("%d\n",ans);
	}
	return 0;
}

