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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int a[N];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int cnt=n,ans=0;
		while(cnt>0){
			if(cnt==1){
				ans+=a[1];
				cnt--;
			}
			else if(cnt==2){
				ans+=a[2];
				cnt-=2;
			}
			else if(cnt==3){
				ans+=a[1]+a[2]+a[3];
				cnt-=3;
			}
			else{
				//令a,b,c,d分别为最小，次小，最大，次大 
				//方案1:a和b,a回,c和d,b回
				//方案2:a和c,a回,a和d,a回 
				ans+=min(a[1]+2*a[2]+a[cnt],2*a[1]+a[cnt]+a[cnt-1]);
				cnt-=2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

