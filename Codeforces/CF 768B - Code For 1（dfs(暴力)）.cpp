#include<iostream>
#include<cstdio>
using namespace std;
const int M=3e7+3e6;
unsigned long long a[M],l,r,ans=0,count=0;

void dfs(unsigned long long n){
	//遇到已经记录过的，且在l左边的，可以直接跳过 
	if(n<M){
		if(a[n]&&count+a[n]<l){
			count+=a[n];
			return;
		}		
	}
	//超过r就不用再找了 
	if(count>r)
		return;
	if(n==0||n==1){
		count++;
		if(count<=r&&count>=l){
			ans+=n;
		}
			return;
	}
	dfs(n/2);	
	dfs(n%2);
	dfs(n/2);
	//这里做一个记录，不然会超时，a[n]代表n完全分解可以分成多少个数（1或0） 
	if(n<M){
		if(!a[n]){
			a[n]=count;
		}	
	}	
}

int main(){
	unsigned long long x;
	cin>>x>>l>>r;
	//直接根据题意爆搜 
	dfs(x);
	cout<<ans<<endl;
	cout<<count<<endl;
}
