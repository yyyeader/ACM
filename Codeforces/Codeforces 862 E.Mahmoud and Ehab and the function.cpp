#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1e5+5;

LL add[N];
LL odd[N],even[N];
LL b[N];

int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	LL sum=0;
	for(int i=1;i<=n;i++){
		LL x;
		scanf("%lld",&x);
		if(i&1)
			sum+=x;
		else
			sum-=x;
	}
	for(int i=1;i<=m;i++){
		LL x;
		scanf("%lld",&x);
		if(i&1){
			odd[i]=odd[i-1]+x;
			even[i]=even[i-1];
		}
		else{
			even[i]=even[i-1]+x;
			odd[i]=odd[i-1];
		}
	}
	LL ans=1e18;
	for(int i=0;m-i>=n;i++){
		if(i%2==0)
			b[i]=(even[i+n]-even[i])-(odd[i+n]-odd[i]);
		else
			b[i]=(odd[i+n]-odd[i])-(even[i+n]-even[i]);
		b[i]=-b[i];
	}
	sort(b,b+m-n+1);
	
	int pos=lower_bound(b,b+m-n,sum)-b;
	if(pos==0)
		ans=abs(-b[pos]+sum);
	else
		ans=min(abs(-b[pos]+sum),abs(-b[pos-1]+sum));
	printf("%lld\n",ans);
	for(int k=1;k<=q;k++){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if((r-l+1)%2!=0){
			if(l%2==0)
				sum-=x;
			else
				sum+=x;
		}			
		ans=1e18;
		int pos=lower_bound(b,b+m-n,sum)-b;
		if(pos==0)
			ans=abs(-b[pos]+sum);
		else
			ans=min(abs(-b[pos]+sum),abs(-b[pos-1]+sum));
		printf("%lld\n",ans);
	}
	return 0;
}
