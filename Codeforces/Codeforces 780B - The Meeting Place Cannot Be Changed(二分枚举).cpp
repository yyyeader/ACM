#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
struct node{
	double x;
	double v; 
}a[N];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i].x);
	}
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i].v);
	}
	
	double ans=1<<30;
	double l=0,r=1e11,mid;
	while(r-l>1e-7){//要求误差小于10^-6 
		mid=(l+r)/2;
		double L=a[1].x-a[1].v*mid;
		double R=a[1].x+a[1].v*mid;
		//求每个人在mid时间内能够到达的范围区间，取交集 
		for(int i=2;i<=n;i++){
			L=max(a[i].x-a[i].v*mid,L);
			R=min(a[i].x+a[i].v*mid,R);
		}
		if(R-L>1e-11){//如果有交集说明大家可以遇到,可以找更小的时间 
			ans=min(ans,mid);
			r=mid;
		}
		else
			l=mid;	
	}
	printf("%.9lf\n",ans);
} 
