#include<stdio.h>
int main(){
	//freopen("in.txt","r",stdin);
	long long n,ans,q;//数据太大，用long long 
	scanf("%d",&q);
	while(q--){
		scanf("%lld",&n);
		long long temp=1;
		ans=n;
		ans%=10;// 取余不影响最终结果 
		while(n!=1){
			if(n%2==1){//如果n%2==1，例如3*3*3,当ans=(3*3), 还有一个3空出来了，用temp留下 
				temp*=ans;
				temp%=10;
			}
			ans*=ans;//ans*ans，可以以将本来为n次的过程,缩减为n/2次,比如4*4*4*4=（4*4）*（4*4）,从4次变为2次；    
			ans%=10;
			n/=2;
		}
		ans*=temp;
		ans%=10;
		printf("%lld\n",ans);
	}
}
