#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=5e4+5;
const int INF=0x3f3f3f3f;

int head,tail;
LL dp[N][105],q[N];

struct node{
	LL w,h;	
	bool operator <(const node &b)const{
		return w==b.w?h>b.h:w>b.w;
	}
}a[N],tmp[N];

LL getUP(int m,int k,int j){
	return dp[k][j-1]-dp[m][j-1];
}

LL getDOWN(int m,int k){
	return a[m+1].h-a[k+1].h;
}

LL getDP(int i,int j,int k){
	return dp[k][j-1]+a[k+1].h*a[i].w;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lld %lld",&tmp[i].w,&tmp[i].h);
		}
		sort(tmp+1,tmp+1+n);
		int cnt=1;
		a[1].h=tmp[1].h,a[1].w=tmp[1].w;
		//删除会被完全覆盖的矩形 
		for(int i=1;i<=n;i++){
			if(a[cnt].h<tmp[i].h){
				cnt++;
				a[cnt].h=tmp[i].h;
				a[cnt].w=tmp[i].w;
			}
		}
		reverse(a+1,a+1+cnt);
		for(int i=1;i<=cnt;i++){
			dp[i][1]=a[1].h*a[i].w;
		}
		LL ans=dp[cnt][1];
		
		for(int j=2;j<=m;j++){
			head=tail=0;
			q[tail++]=j-1;
			dp[cnt][j]=INF;
			for(int i=j;i<=cnt;i++){
				while(head+1<tail&&getUP(q[head],q[head+1],j)<=a[i].w*getDOWN(q[head],q[head+1])){
					head++;
				}
				dp[i][j]=getDP(i,j,q[head]);
				while(head+1<tail&&getUP(q[tail-1],i,j)*getDOWN(q[tail-2],q[tail-1])<=getUP(q[tail-2],q[tail-1],j)*getDOWN(q[tail-1],i)){
					tail--;
				}
				q[tail++]=i;
			}
			//加一句特判(从超时变成146ms),当挖洞数增多,花费未降低的时候,说明再增加挖洞数也不会降低花费,直接结束DP 
			if(ans<=dp[cnt][j])
				break;
			else
				ans=dp[cnt][j];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
