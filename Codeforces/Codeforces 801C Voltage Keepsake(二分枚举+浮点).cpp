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
	
	if(sum<=add)//��繦�ʴ������Ĺ����ܺͣ�˵������һֱ����ȥ 
		printf("-1\n");
	else{
		double l=0,r=1e11;
		double t0=1e-5;
		//����ö��ʱ�� 
		while(r-l>t0){//Ϊ����ʱ�侫�ȴ���1e-4; 
			double mid=(l+r)/2;
			double k=0;
			for(int i=1;i<=n;i++){
				if(a[i].cost*mid>a[i].time){//�����ǰ�ĵ��������Ǿ���Ҫ����� 
					k+=(a[i].cost*mid-a[i].time)/add;//kֵ���������ܳ��ʱ�䣬(a[i].cost*mid-a[i].time)/add��ʾ�Ǹõ���ʹ��mid��������ʱ�� 
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
