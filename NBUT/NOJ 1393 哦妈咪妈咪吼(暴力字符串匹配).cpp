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

char s[1005][50],t[50];

int main(){
	int n,q;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]);
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%s",t);
			int ans=0;
			for(int j=1;j<=n;j++){
				int cnt=0;
				for(int k=0;s[j][k]!='\0'&&t[k]!='\0';k++){
					if(s[j][k]!=t[k])
						break;
					cnt++;
				}
				if(cnt==strlen(t))
					ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

