#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib> 
#include<time.h>
using namespace std;
const int N=1e6+5;
typedef long long LL;
struct node {
	int a;
	int b;
	int num;
}t[N];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	LL asum=0,bsum=0;
	for(int i=1;i<=n;i++){
		cin>>t[i].a;
		asum+=t[i].a;
	}
	for(int i=1;i<=n;i++){
		cin>>t[i].b;
		t[i].num=i;
		bsum+=t[i].b;
	}
	cout<<n/2+1<<endl;
	srand(time(NULL));
	while (1) {
		random_shuffle(t+1, t+n+1);
		LL ta=0,tb=0;
		for(int i=1;i<=n/2+1;i++){
			ta+=t[i].a;
			tb+=t[i].b;
		} 
		if (2*ta>asum&&2*tb>bsum) {
			for(int i=1;i<=n/2+1;i++){
				cout<<t[i].num<<" ";
			}
			cout<<endl;
			return 0;
		}
	}
	return 0;
} 
