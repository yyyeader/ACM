#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int t,m,n;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int ans;
		scanf("%d%d",&m,&n);
		if(m>2&&n>2)
			ans=(m*n+1)/2;	
		if(m==1||n==1){
			ans=m*n;
		}
		else if(m==2||n==2){
			if(m<n)
				swap(m,n);
			ans=m/4*4;
			//匹配了成对田字格后剩下的格子 
			int tmp=m-m/4*4;
			if(m%4>=2)
				ans+=4;
			else
				ans+=m%4*2;
		}
		printf("Case %d: %d\n",i,ans);
	}
} 
