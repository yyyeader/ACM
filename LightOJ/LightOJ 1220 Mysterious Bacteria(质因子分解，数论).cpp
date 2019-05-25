#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=2e5+10;
bool prime[N];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

void Prime_init(){
	int i,j;
	for(i=2;i<N;i++)
		prime[i]=true;
	for(i=2;i*i<N;i++){
		if(prime[i]){
			for(j=i*i;j<N;j+=i){
				prime[j]=false;
			}
		}
	}
}

int main(){
	Prime_init();
	int a[50];
	int n,i,j,count,ans;
	long long x,temp;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x;
		count=0;
		memset(a,0,sizeof(a));
		temp=abs(x);
		for(j=2;j<=sqrt(temp);j++){
			if(prime[j]&&temp%j==0){
				while(temp%j==0){
					temp/=j;
					a[count]++;
				}
				count++;
			}
		}
		ans=max(1,a[0]); 
		for(j=1;j<count;j++){
			ans=gcd(ans,a[j]);
		}
		if(x<0){
			while(ans%2==0){
				ans/=2;
			}
		}
		cout<<"Case "<<i<<": "<<ans<<endl; 
	}
}

