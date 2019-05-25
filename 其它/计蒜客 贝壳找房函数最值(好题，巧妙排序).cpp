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
const int N=1e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

struct node{
	int a,b;
}p[N];

bool cmp(node x,node y){
	return x.a*y.b+x.b>y.a*x.b+y.b;
}

int main(){
	FAST_IO;
	int T;
	cin>>T;
	while(T--){
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=n;i++){
			cin>>p[i].a;
		}
		for(int i=1;i<=n;i++){
			cin>>p[i].b;
		}
		sort(p+1,p+1+n,cmp);
		int ans=0,tmp=1;
		for(int i=1;i<=n;i++){
			ans=(ans+tmp*p[i].b)%10;
			tmp=tmp*p[i].a%10;
		}
		ans=(ans+tmp*x)%10;
		cout<<ans<<endl;
	}
	return 0;
}

