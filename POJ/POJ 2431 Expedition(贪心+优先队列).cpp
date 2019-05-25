#include<iostream>
#include<queue> 
#include<algorithm> 
using namespace std;
struct node{
	int dis;
	int gas;
}a[10005];

bool cmp(node a,node b){
	return a.dis<b.dis;
}
int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>a[i].dis>>a[i].gas; 
		}
		int l,p; 
		cin>>l>>p;
		//终点 
		a[n+1].dis=l;
		a[n+1].gas=0;
		//将加油站到终点距离变为离起点距离并从小到大排好 
		for(int i=1;i<=n;i++){
			a[i].dis=l-a[i].dis;
		}
		sort(a+1,a+n+2,cmp);
		//优先队列,从大到小
		priority_queue<int>q; 
		//ans:加油次数,pos:当前位置，tank:剩余油量 
		int ans=0,pos=0,tank=p;
		for(int i=1;i<=n+1;i++){
			//当前位置离下一个加油站的距离 
			int x=a[i].dis-pos;
			while(tank<x){
				if(q.empty()){
					cout<<"-1"<<endl;
					return 0;
				}
				tank+=q.top();
				q.pop();
				ans++;
			}
			tank-=x;
			pos=a[i].dis;
			q.push(a[i].gas);	
		}
		cout<<ans<<endl;
	}
	return 0;	
}
