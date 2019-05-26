#include<iostream>
using namespace std;
typedef unsigned long long ll;
ll judge(ll x){
	ll n=1;
	while(x/10){
		x/=10;
		n++;
	}
	return n;
}

ll pow(ll m,ll n){
	ll res=1;
	if(n==0)
		return res;
	for(int i=1;i<=n;i++){
		res*=m;
	}
	return res;
}

int main(){
	ll n=0,num=0;
	cin>>n;
	num=judge(n);
	ll tmp=n/pow(10,num-1)*pow(10,num-1);
	ll max=tmp-1;
	if(num==1){
		cout<<n<<endl;
	}
	else{
		if(n==(n/pow(10,num-1)+1)*pow(10,num-1)-1){
			max=n;
		}		
		else{
			tmp=(n/pow(10,num-1)+1)*pow(10,num-1)-1;
			for(int i=num-2;i>=0;i--){
				ll res=8*pow(10,i);
				ll ret=9*pow(10,i);	
				if(tmp-ret+res<=n)
					max=tmp-ret+res;
			}
		}	
		cout<<max<<endl;
	}
} 
