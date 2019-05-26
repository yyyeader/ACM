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
			//其实不用每个数都找一遍那样肯定超时，比如580，可以先找499再找599，如果找不到，那接下来的数如598最多与499相同 
			//根据题目要求各位和相同取较大值
			//所以我们可以按大小顺序取589，598如果比n小那就取过来 
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
