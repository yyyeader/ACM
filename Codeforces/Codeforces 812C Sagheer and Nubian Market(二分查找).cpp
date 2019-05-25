#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+5;

ll a[N],b[N];

bool cmp(ll a,ll b){
	return a<b;
}

int main(){
	ll n,s,cost=0;
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		ll sum=0;
		//���㹺��ǰ����,������Ʒ����۸� 
		for(int i=1;i<=n;i++){
			b[i]=a[i]+mid*i;
		}
		//ע��Ҫ���򣬿��ܺ������Ʒ�۸�� 
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=mid;i++){
			sum+=b[i];
			if(sum>s)
				break;
		} 
		if(sum<=s){
			l=mid+1;
			cost=sum;
		}	
		else
			r=mid-1;
	}
	cout<<r<<" "<<cost<<endl;	
} 
