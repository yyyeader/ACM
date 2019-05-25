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

LL s1[N],s2[N],s3[N],s4[N],s5[N],s6[N],s7[N],s8[N];
LL a[N][3],flag[N][3];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][1]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][2]);
	}
	for(int i=1;i<=n;i++) s1[i]=a[i][1]+s1[i-1];
	for(int i=n;i>=1;i--) s2[i]=a[i][1]+s2[i+1];
	for(int i=1;i<=n;i++) s3[i]=(i-1)*a[i][1]+s3[i-1];
	for(int i=n;i>=1;i--) s4[i]=(n-i)*a[i][1]+s4[i+1];
	for(int i=1;i<=n;i++) s5[i]=a[i][2]+s5[i-1];
	for(int i=n;i>=1;i--) s6[i]=a[i][2]+s6[i+1];
	for(int i=1;i<=n;i++) s7[i]=(i-1)*a[i][2]+s7[i-1];
	for(int i=n;i>=1;i--) s8[i]=(n-i)*a[i][2]+s8[i+1];
	LL ans=0,tans=0,cnt=1,x=1,y=1;
	//总共只有四种状态的走法,把所有走法答案求出取最大 
	while(cnt<=2*n){
		ans+=(cnt-1)*a[x][y];
		flag[x][y]=1;
		if(y==1){
			if(flag[x][y+1]){
				x++;
			}
			else{
				LL t=cnt;//在(x+1,y)位置的时间
				LL tmp=ans+(t-x)*(s1[n]-s1[x])+(s3[n]-s3[x]);
				t=t+n-x;
				tmp=tmp+t*(s6[x]-s6[n+1])+(s8[x]-s8[n+1]);
				tans=max(tans,tmp);
				y++;
			}
		}
		else{
			if(flag[x][y-1]){
				x++;
			}
			else{
				LL t=cnt;//在(x+1,y)位置的时间
				LL tmp=ans+(t-x)*(s5[n]-s5[x])+(s7[n]-s7[x]);
				t=t+n-x;
				tmp=tmp+t*(s2[x]-s2[n+1])+(s4[x]-s4[n+1]);
				tans=max(tans,tmp);
				y--;
			}
		}
		cnt++;
	}
	printf("%lld\n",max(tans,ans));
	return 0;
}

