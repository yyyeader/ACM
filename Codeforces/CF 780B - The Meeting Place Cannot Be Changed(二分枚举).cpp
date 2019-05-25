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
	while(r-l>1e-7){//Ҫ�����С��10^-6 
		mid=(l+r)/2;
		double L=a[1].x-a[1].v*mid;
		double R=a[1].x+a[1].v*mid;
		//��ÿ������midʱ�����ܹ�����ķ�Χ���䣬ȡ���� 
		for(int i=2;i<=n;i++){
			L=max(a[i].x-a[i].v*mid,L);
			R=min(a[i].x+a[i].v*mid,R);
		}
		if(R-L>1e-11){//����н���˵����ҿ�������,�����Ҹ�С��ʱ�� 
			ans=min(ans,mid);
			r=mid;
		}
		else
			l=mid;	
	}
	printf("%.9lf\n",ans);
} 
