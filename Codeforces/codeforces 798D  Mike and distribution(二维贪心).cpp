#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+5;

struct node {
	int a;
	int b;
	int num;
}t[N];

bool cmp(node x,node y){
	return x.a>y.a;//第一层按从大到小排好
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a;
	}
	for(int i=1;i<=n;i++){
		cin>>t[i].b;
		t[i].num=i;
	}
	sort(t+1,t+1+n,cmp);
	cout<<n/2+1<<endl;
	cout<<t[1].num<<" ";
	for(int i=2;i<=n;i+=2){
		cout<<(t[i].b>t[i+1].b?t[i].num:t[i+1].num)<<" ";//两两取较大的那个 
	}
	cout<<endl;
	return 0;
} 
