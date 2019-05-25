#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=2e5+5;
typedef long long LL;
LL a[N];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	LL l=2,r=4e18,mmax=-1,mmin=4e18;
	//找最小的使得g(x)>=2成立的数，即mmax 
	while(l<=r){
		LL mid=(l+r)/2;
		LL num=mid;
		for(int i=1;i<=n;i++){
			num=num/a[i]*a[i];
		}
		if(num>=2){
			mmin=mid;
			r=mid-1;
		}		
		else
			l=mid+1;
	}
	//找最大的使得g(x)<=2成立的数,即mmin 
	l=2,r=4e18;
	while(l<=r){
		LL mid=(l+r)/2;
		LL num=mid;
		for(int i=1;i<=n;i++){
			num=num/a[i]*a[i];
		}
		if(num<=2){
			mmax=mid;
			l=mid+1;		
		}		
		else
			r=mid-1;
	}
	if(mmin<=mmax)
		printf("%lld %lld\n",mmin,mmax);
	else
		puts("-1");
	return 0;
}


