#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=2e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

LL a[N],b[N],suma[N],sumb[N];

int main(){
	FAST_IO;
	int n,m;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]+=a[i-1];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
			b[i]+=b[i-1];
		}
		LL x;
		cin>>x;
		memset(suma,0x3f,sizeof(suma));
		memset(sumb,0x3f,sizeof(sumb));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i+j-1<=n)
					suma[i]=min(suma[i],a[i+j-1]-a[j-1]);
				else break;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i+j-1<=m)
					sumb[i]=min(sumb[i],b[i+j-1]-b[j-1]);
				else break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				if(suma[i]*sumb[j]<=x)
					ans=max(ans,i*j);
		}
		cout<<ans<<endl;
	}
	return 0;
}

