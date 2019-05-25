#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#define LL long long
#define ll __int64
#define INF 0x3f3f3f3f
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-10
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
LL powmod(LL a,LL b,LL MOD){LL ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}

const int MAXN=2e2+5;
int n,m;
char mp[300][300];
int main()
{
	int t;
	si(t);
	while(t--)
	{
		si(n);
		si(m);
		for(int i=1;i<=n;i++)
		{
			getchar();
			scanf("%s",mp[i]+1);
		}
		LL ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
			//	if(i==j)continue;
				int _b,_j,_h,_y,_n;
				_b=_j=_h=_y=_n=0;
				for(int k=1;k<=m;k++){
					if(mp[i][k]==mp[j][k]){
						if(mp[i][k]=='B')_b++;
						if(mp[i][k]=='J')_j++;
						if(mp[i][k]=='H')_h++;
						if(mp[i][k]=='Y')_y++;
						if(mp[i][k]=='N')_n++;
					}
				}
				ans+=1LL*_b*(_b-1)/2;
				ans+=1LL*_j*(_j-1)/2;
				ans+=1LL*_h*(_h-1)/2;
				ans+=1LL*_y*(_y-1)/2;
				ans+=1LL*_n*(_n-1)/2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
