#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+5;

double high[N];

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		double h=0;
		for(int j=max(0,x-2*r);j<=x+2*r;j++){
			if(high[j]>0){
				double t=high[j]+sqrt(4*r*r-(x-j)*(x-j));
				h=max(h,t);	
			}
		}
		if(h==0)
			high[x]=r;
		else
			high[x]=h;
		printf("%.8f ",high[x]);
	}
	return 0;
}
