#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=3e5+5;

int n,k;
int a[N],sum[N];

int main(){
	FAST_IO;
	cin>>n>>k;
	int cnt=0,idx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1];
		if(a[i]==0)
			sum[i]++;
	}
	int st=1,en=1,ans=0,ast=0,aen=0;
	while(en<=n){
		while(en<=n&&sum[en]-sum[st-1]<=k){
			if(ans<en-st+1){
				ans=en-st+1;
				ast=st;
				aen=en;
			}
			en++;
		}
		st++;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(i>=ast&&i<=aen)
			cout<<1<<" ";
		else
			cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
