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
		//�յ� 
		a[n+1].dis=l;
		a[n+1].gas=0;
		//������վ���յ�����Ϊ�������벢��С�����ź� 
		for(int i=1;i<=n;i++){
			a[i].dis=l-a[i].dis;
		}
		sort(a+1,a+n+2,cmp);
		//���ȶ���,�Ӵ�С
		priority_queue<int>q; 
		//ans:���ʹ���,pos:��ǰλ�ã�tank:ʣ������ 
		int ans=0,pos=0,tank=p;
		for(int i=1;i<=n+1;i++){
			//��ǰλ������һ������վ�ľ��� 
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
