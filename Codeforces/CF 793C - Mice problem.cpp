#include<iostream>
#include<algorithm>
using namespace std;
double l=0,r=1e11;

void updata(int pos,int lb,int rb,int v){
	if(v==0){
		if(pos>lb&&pos<rb)//为什么不能=，也就是刚好在边界上？ 
			return;
		r=-1;
	}
	double t1=(double)(lb-pos)/v,t2=(double)(rb-pos)/v;
	if(t1>t2)
		swap(t1,t2);
	l=max(l,t1);
	r=min(r,t2);
	printf("t1=%.11lf t2=%.11lf\n",t1,t2);
}

int main(){
	int n;
	int x1,y1,x2,y2;
	scanf("%d",&n);
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	for(int i=1;i<=n;i++){
		int x,y,vix,viy;
		scanf("%d %d %d %d",&x,&y,&vix,&viy);
		updata(x,x1,x2,vix);
		updata(y,y1,y2,viy);
		printf("l=%.10lf r=%.10lf\n",l,r);		
	}
	if(r-l>e-11&&r>0)//l和r只能无限接近，不能等于，暂时认为在边界上是不行的 
		printf("%.10lf\n",l);
	else
		printf("-1\n");
	return 0;
}
