#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long LL;
const int N=20;
LL m[N],a[N],n;
//扩展欧几里得 
void exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x=1;
		y=0;
	}
	else{
		exgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}	
}
//中国剩余余定理 
LL CRT(){
	LL M=1;
	for(int i=1;i<=n;i++)
		M*=m[i];
	LL ans=0;
	for(int i=1;i<=n;i++){
		LL x,y,Mi;
		Mi=M/m[i];
		exgcd(Mi,m[i],x,y);
		ans=(ans+a[i]*Mi*x)%M;
	}
	if(ans<0) ans+=M;
	return ans;	
}

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&m[i],&a[i]);
		}
		printf("Case %d: %lld\n",++cas,CRT());
	}
}
