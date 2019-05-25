#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
	double l,r;
	bool operator <(node &b)const{
		return l<b.l;
	}
}a[N];

int main(){
	double L,D;
	int n;
	while(~scanf("%lf",&L)){
		scanf("%lf%d",&D,&n);
		for(int i=1;i<=n;i++){
			double x,y;
			scanf("%lf %lf",&x,&y);
			a[i].l=x-sqrt(D*D-y*y);
			a[i].r=x+sqrt(D*D-y*y);
		}
		sort(a+1,a+1+n);
		double en=-1e9;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].l>en){
				en=a[i].r;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

