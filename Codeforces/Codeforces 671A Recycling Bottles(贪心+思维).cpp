#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

double dis(int x,int y,int a,int b){
	return sqrt(1.0*(x-a)*(x-a)+1.0*(y-b)*(y-b));
}

int main(){
	int ax,ay,bx,by,tx,ty;
	scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&tx,&ty);
	double sum=0;
	double ma=1e18,mb=1e18,mab=1e18;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		double dt=dis(tx,ty,x,y);
		double da=dis(ax,ay,x,y)-dt;//��A�õĴ��� 
		double db=dis(bx,by,x,y)-dt;//��B�õĴ���
		sum+=dt*2;
		mab=min(mab,min(ma+db,mb+da));
		ma=min(ma,da),mb=min(mb,db);
	}
	printf("%.12f",sum+min(mab,min(ma,mb)));//A��һ��B��һ������ֻ��A�ã���ֻ��B�� 
	return 0;
}
