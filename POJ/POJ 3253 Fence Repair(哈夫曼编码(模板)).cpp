#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
//输入
int n,a[20005];

//使用数组维护最大最小值(每次维护复杂度O(n)) 
void solve1(){
	ll ans=0;
	
	while(n>1){
		int mi1=0,mi2=1;//mi1最小值的下标，mi2次小值的下标 
		if(a[mi1]>a[mi2]) swap(mi1,mi2);
		for(int i=2;i<n;i++){
			if(a[mi1]>a[i]){
				mi2=mi1;
				mi1=i;	
			}
			else if(a[mi2]>a[i]){
				mi2=i;
			}
		}
		int t=a[mi1]+a[mi2];
		ans+=t;
		if(mi1==n-1) swap(mi1,mi2);
		a[mi1]=t;
		a[mi2]=a[n-1];
		n--;
//		for(int i=0;i<n;i++){
//			cout<<a[i]<<(i==n-1?'\n':' ');
//		}
	}
	cout<<ans<<endl;
}

//优先队列维护最小与次小值(初始化复杂度O(n),每次维护复杂度O(log2n))
void solve2(){
	priority_queue<ll,vector<ll>,greater<ll> >q;
	ll ans=0;
	for(int i=0;i<n;i++){
		q.push(a[i]);
	}
	while(q.size()>1){
		ll mi1=q.top();//最小
		q.pop();
		ll mi2=q.top();//次小
		q.pop();
		q.push(mi1+mi2);//合并 
		ans+=mi1+mi2; 
	}
	cout<<ans<<endl;
} 


int main(){ 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//solve1(); 
	solve2(); 
	return 0;
} 
