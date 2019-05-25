#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=2e5+5;
set<int>ms[5];
struct node{
	int val,front,back;
}a[N];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].front;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].back;
	}
	for(int i=1;i<=n;i++){
		ms[a[i].front].insert(a[i].val);
		ms[a[i].back].insert(a[i].val);
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		if(ms[x].size()==0)
			cout<<"-1"<<endl;
		else{
			int curval=*(ms[x].begin());
			cout<<curval<<" ";
			for(int i=1;i<=3;i++){
				ms[i].erase(curval); 
			}
		}	
	}
}
