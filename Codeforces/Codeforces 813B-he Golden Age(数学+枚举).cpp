#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<ll>v;

int main(){
	ll x,y,l,r;
	cin>>x>>y>>l>>r;
	ll tx,ty;
	ll d1=r;
	for(int i=0;i<=61;i++){
		if(i!=0)
			d1/=x;
		if(d1==0)
			break;
		if(i==0)
			tx=1;
		else
			tx*=x;
		ll d2=r;
		for(int j=0;j<=61;j++){
			if(j!=0)
				d2/=y;
			if(d2==0)
				break;
			if(j==0)
				ty=1;
			else
				ty*=y;
			if(tx+ty>=l&&tx+ty<=r){
				v.push_back(tx+ty);
			}		
		}
	}	
	//vectorΪ�յ���� 
	if(!v.size()){
		cout<<r-l+1<<endl;
		return 0;
	}
	
	ll ans=0;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		//���l����unlucky���֣��ǾͶ������v[0]-l������� 
		if(i==0&&v[0]!=l)
			ans=max(ans,v[i]-l);
		//���r����unlucky���֣��Ͷ������r-v[v.size()-1]������� 
		if(i==v.size()-1){
			if(!sign2)
				ans=max(ans,r-v[i]);
		}
		else
			ans=max(ans,v[i+1]-v[i]-1);
	}
	cout<<ans<<endl;
}
