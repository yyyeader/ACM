#include<iostream>
using namespace std;
typedef long long ll;
ll ans=0;
void dfs(ll a,ll b,ll l,ll r,ll d){//���ֵ�˼�� 
	if(a>b||l>r)
		return;
	ll mid=(a+b)/2;
	if(r<mid)
		dfs(a,mid-1,l,r,d/2);
	else if(l>mid)
		dfs(mid+1,b,l,r,d/2);
	else{
		ans+=d%2;
		dfs(a,mid-1,l,mid-1,d/2);
		dfs(mid+1,b,mid+1,r,d/2);
	}
}

int main(){
	ll l,r,n,s=1;
	cin>>n>>l>>r;
	ll temp=n;
	//����֪��n���Էֳ�n/2,n%2,n/2,����nÿ�α��n/2����һ��n%2����������s=s*2+1;
	while(temp>=2){
		temp/=2;
		s=s*2+1;
	}
	dfs(1,s,l,r,n);
	cout<<ans<<endl;
}
