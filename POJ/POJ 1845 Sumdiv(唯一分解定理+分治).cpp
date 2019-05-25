#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const double eps=1e-8;
const int N=1e5+5;
const int M=1e5+5;
const int INF=0x3f3f3f3f;
const LL MOD=9901;

LL cnt[N],fac[N],idx;

LL fmod(LL a,LL b,LL p){
	LL ans=1;
	while(b){
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}

LL sum(LL p,LL c){
	if(p==0) return 0;
	if(c==0) return 1;
	if(c%2) 
		return (1+fmod(p,(c+1)/2,MOD))*sum(p,(c-1)/2)%MOD;
	else
		return ((1+fmod(p,c/2,MOD))*sum(p,c/2-1)+fmod(p,c,MOD))%MOD;
}

int main(){
	FAST_IO;
	LL A,B;
	while(cin>>A>>B){
		idx=0; 
		for(int i=2;i*i<=A;i++){
			if(A%i==0){
				fac[++idx]=i;
				cnt[idx]=0;
				while(A%i==0){
					cnt[idx]++;
					A/=i;
				}
			}
		}
		if(A!=1){
			fac[++idx]=A;
			cnt[idx]=1;
		}
		LL ans=1; 
		for(int i=1;i<=idx;i++){
			ans=ans*sum(fac[i],cnt[i]*B)%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}

