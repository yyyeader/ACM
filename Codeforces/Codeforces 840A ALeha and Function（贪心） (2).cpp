/*贪心，A越大，B越小，越好*/ 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;

struct node{
	int pos,num;
	bool operator <(const node &t)const{
		return num<t.num;
	}
}b[N];

int a[N],res[N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i].num);
		b[i].pos=i; 
	}
	sort(b+1,b+1+n);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		res[b[i].pos]=a[i];
	}
	for(int i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
	puts("");
	return 0;
} 
