#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double L,W;

double fun(double x){
	return x*(L-2*x)*(W-2*x);
}

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%lf%lf",&L,&W);
		double pos=(4*(L+W)-sqrt(16*(L+W)*(L+W)-4*12*L*W))/24.0;
		printf("Case %d: %lf\n",++cas,fun(pos));
	}	
} 
