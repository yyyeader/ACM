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

int a[N],b[N];
int mp[1005][1005];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum1^=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		sum2^=b[i];
	}
	if(sum1!=sum2) puts("NO");
	else{
		puts("YES");
		mp[1][1]=sum2^a[1]^b[1];
		for(int i=2;i<=m;i++){
			mp[1][i]=b[i];
		}
		for(int i=2;i<=n;i++){
			mp[i][1]=a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",mp[i][j]);
			}
			puts("");
		}
	}
	return 0;
}

