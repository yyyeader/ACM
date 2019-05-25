#include<iostream>
#include<cstdio>
using namespace std;

int sum=0;

void hanoi(int n,char a,char b,char c){
	if(n==1){
		printf("sum=%d %dºÅÅÌ×Ó %c -> %c\n",++sum,n,a,c);
		return;
	}
	else{
		hanoi(n-1,a,c,b);
		printf("sum=%d %dºÅÅÌ×Ó %c -> %c\n",++sum,n,a,c);
		hanoi(n-1,b,a,c);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
}
