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
const LL INF=4e18;

LL a[N];

int main(){
	FAST_IO;
	LL n;
	cin>>n;
	rep(i,1,2*n){
		cin>>a[i];
	}
	sort(a+1,a+1+2*n);
	LL ans=(a[2*n]-a[n+1])*(a[n]-a[1]);
	LL C=a[2*n]-a[1];
	rep(i,2,n){
		LL temp=C*(a[i+n-1]-a[i]);
		ans=min(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}

