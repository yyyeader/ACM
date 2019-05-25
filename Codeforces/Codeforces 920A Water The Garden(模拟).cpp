#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e3+5;
int a[N];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans=0;
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}
		if(k==1)
			ans=max(a[1]-1+1,n-a[1]+1);
		else{
			for(int i=1;i<=k;i++){
				int p1=a[i-1]+(a[i]-a[i-1]+1)/2;
				int p2=a[i+1]-(a[i+1]-a[i]+1)/2;
				if(i==1)
					ans=max(ans,max(a[i],p2-a[i]+1));
				else if(i==k)
					ans=max(ans,max(a[i]-p1+1,n-a[i]+1));
				else
					ans=max(ans,max(a[i]-p1+1,p2-a[i]+1));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
