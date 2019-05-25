#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
const int N=1e6+5;

int a[N];

void Qsort(int l,int r){
	if(l>=r)
		return;
	int i=l,j=r,pivot=a[l];
	while(i<j){
		while(i<j&&a[j]>=pivot)
			j--;
		while(i<j&&a[i]<=pivot)
			i++;
		if(i<j)
			swap(a[i],a[j]);
	}
	swap(a[l],a[i]);
	Qsort(l,i-1);
	Qsort(i+1,r);
}


int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		Qsort(1,n);
		for(int i=n;i>=n-m+1;i--){
			printf("%d%c",a[i],(i==n-m+1?'\n':' '));
		}
	}
	return 0;
}
