#include<stdio.h>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;

double pi=acos(-1);

int main(){
	int n;
	double r;
	while(~scanf("%d%lf",&n,&r)){
		double len=2*pi*r,x0,y0,px,py;
		scanf("%lf%lf",&x0,&y0);
		px=x0;
		py=y0;
		for(int i=1;i<n;i++){
			double x,y;
			scanf("%lf%lf",&x,&y);
			len+=sqrt((px-x)*(px-x)+(py-y)*(py-y));
			px=x;
			py=y;
		}
		len+=sqrt((px-x0)*(px-x0)+(py-y0)*(py-y0));
		printf("%.2f\n",len);
	}
	return 0;
}
