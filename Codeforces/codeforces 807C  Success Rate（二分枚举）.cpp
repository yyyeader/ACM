#include<iostream>
#include<cstdio> 
using namespace std;
typedef long long LL;

int main(){
	int T;
	cin>>T;
	while(T--){
		LL x,y,p,q;
		cin>>x>>y>>p>>q;
		LL l=0,r=1e10,mid;
		LL ans=1<<30;
		while(l<=r){
			mid=(l+r)/2; 
			LL A=mid*p-x;
			LL B=mid*q-y;
			if(A>=0&&B>=0&&A<=B){//ÅÐ¶ÏÊÇ·ñÂú×ã£¨0<=A<=B£© 
				ans=min(ans,mid);
				r=mid-1;
			} 
			else
				l=mid+1;
		}
		if(ans!=1<<30)
			cout<<ans*q-y<<endl; 
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
