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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int main(){
	FAST_IO;
	LL n,k,s;
	cin>>n>>k>>s;
	if(s>k*(n-1)||s<k){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	LL st=1;
	while(k){
		LL mmax=n-1;
		if(s-mmax>=k-1){
			s-=mmax;
			if(st+mmax>n)
				st-=mmax;
			else
				st+=mmax;
			cout<<st<<" ";
		}
		else{
			mmax=s-k+1;
			s-=mmax;
			if(st+mmax>n)
				st-=mmax;
			else
				st+=mmax;
			cout<<st<<" ";
		}
		k--;
	}
	cout<<endl;
	return 0;
}

