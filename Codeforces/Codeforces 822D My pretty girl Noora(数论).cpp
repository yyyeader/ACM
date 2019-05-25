#include<iostream>
using namespace std;
typedef long long ll;
const int N=5e6+5;
const ll MOD=1e9+7; 
bool prime[N];
ll p[N];
ll f[N];
int cnt;
//素数表 
void is_prime(){
	for(int i=2;i<=N;i++)
		prime[i]=true;
	for(int i=2;i*i<=N;i++){
		if(prime[i]){
			p[cnt++]=i;
			for(int j=i*i;j<=N;j+=i){
				prime[j]=false;
			}
		}	
	}
}

int main(){
	is_prime();
	f[1]=0;
	for(int i=2;i<N;i++){
		//判断是否为素数 
		if(prime[i]){
			f[i]=((ll)i*(i-1)/2)%MOD;
		}
		else{
			//找最小素因子 
			ll factor;
			for(int j=0;j<cnt;j++){
				if(i%p[j]==0){
					factor=p[j];
					break; 
				}				
			}	
			f[i]=(i/factor*f[factor]+f[i/factor])%MOD;
		}
	}
	ll ans=0;
	ll t,l,r;
	cin>>t>>l>>r;
	for(int i=r;i>=l;i--){
		ans=(ans*t)%MOD;
		ans=(ans+f[i])%MOD;
	}
	cout<<ans<<endl; 
} 
