#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b); 
}

int main(){
	int n,tmp=0;
	int a[N]={0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tmp=gcd(tmp,a[i]);
	}
	if(tmp!=1)//如果不需要操作就得到gcd>1,直接输出0次;
		cout<<"YES"<<"\n"<<"0"<<endl;
	else{
		int ans=0;
		for(int i=1;i<n;i++){//找奇奇 
			if(a[i]&1&&a[i+1]&1){
				ans++;
				a[i]=a[i+1]=2; 
			}
		}
		for(int i=1;i<n;i++){
			if(a[i]&1||a[i+1]&1){//找奇偶或者偶奇 
				ans+=2;
				a[i]=a[i+1]=2;
			}
		}
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	}
	return 0;
}

 
