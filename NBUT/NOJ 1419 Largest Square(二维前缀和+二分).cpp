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
const int N=2e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int T,n,w,l;
bool mp[N][N];
int sum[N][N];

bool judge(int mid){
	for(int i=mid;i<=n;i++){
		for(int j=mid;j<=n;j++){
			int s=sum[i][j]-sum[i-mid][j]-sum[i][j-mid]+sum[i-mid][j-mid];
			if(s<=l) return true;
		}
	}
	return false;
}

int main(){
	scanf("%d",&T);
	while(T--){
		memset(mp,false,sizeof(mp));
		scanf("%d%d%d",&n,&w,&l);
		for(int i=1;i<=w;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			mp[x][y]=true;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
			}
		}
		int ans=0,l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(judge(mid)){
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		printf("%d\n",ans*ans);
	}
	return 0;
}

