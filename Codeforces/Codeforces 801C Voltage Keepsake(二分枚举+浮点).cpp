#include<iostream>
using namespace std;
const int N=1e5+5;
struct node{
	int cost,time;
}a[N];

int main(){
	int n,add;
	long long sum=0;
	scanf("%d %d",&n,&add);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].cost,&a[i].time);
		sum+=a[i].cost; 
	}
	
	if(sum<=add)//充电功率大于消耗功率总和，说明可以一直用下去 
		printf("-1\n");
	else{
		double l=0,r=1e11;
		double t0=1e-5;
		//二分枚举时间 
		while(r-l>t0){//为了让时间精度大于1e-4; 
			double mid=(l+r)/2;
			double k=0;
			for(int i=1;i<=n;i++){
				if(a[i].cost*mid>a[i].time){//如果当前的电量不够那就需要充电器 
					k+=(a[i].cost*mid-a[i].time)/add;//k值就是所需总充电时间，(a[i].cost*mid-a[i].time)/add表示是该电器使用mid秒所需充电时间 
				}
			}
			if(k>mid)
				r=mid;
			else
				l=mid;
		}
		printf("%lf\n",r);
	}
	return 0;	
} 
