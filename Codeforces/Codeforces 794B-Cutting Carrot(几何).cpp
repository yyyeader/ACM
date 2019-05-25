#include<iostream>
#include<math.h>
using namespace std;
const int N=1e3+5;
double a[N];

int main(){
	double n,h;
	scanf("%lf%lf",&n,&h);
	int t=n;
	a[t]=h;
	for(int i=1;i<=n-1;i++){
		double x=sqrt(1-(n-i)/n);
		double h1=x*h;
		if(i==n-1)
			printf("%.12lf\n",h1);
		else
			printf("%.12lf ",h1); 
	}
}
