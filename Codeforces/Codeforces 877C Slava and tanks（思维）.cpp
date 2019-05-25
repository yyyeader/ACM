#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+5;

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",n/2*2+(n-n/2));
	for(int i=2;i<=n;i+=2){
		printf("%d ",i);
	}
	for(int i=1;i<=n;i+=2){
		printf("%d ",i);
	}
	for(int i=2;i<=n;i+=2){
		printf("%d ",i);
	}
	return 0;
}
