#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL unsigned long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
	LL n;
	while(cin>>n){
		LL ans=0;
		LL p=5;
		while(n/p){
			LL t=n/p;
			ans+=(t-1)*t/2*p;
			ans+=(n%p+1)*t;
			p*=5;
		}
		cout<<ans<<endl;
	}
	return 0;
}

