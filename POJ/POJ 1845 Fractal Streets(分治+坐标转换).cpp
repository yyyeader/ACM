#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
#define pll pair<long long,long long>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

//cal(n,m)计算在等级n的城市下，编号为m房屋的坐标 
pll cal(int n,int m){
	if(n==0)  return pll(0,0);
	LL len=1<<(n-1),cnt=1<<(2*n-2),pos=m/cnt;
	pll p=cal(n-1,m%cnt);
	LL x=p.first,y=p.second;
	if(pos==0) return pll(y,x);					//左上,(x,y)->(y,x) 
	if(pos==1) return pll(x,y+len);				//右上,(x,y)->(x,y+2^(n-1))
	if(pos==2) return pll(x+len,y+len);			//右下,(x,y)->(x+2^(n-1),y+2^(n-1))
	if(pos==3) return pll(len*2-y-1,len-x-1);	//左下,(x,y)->(2^n-y-1,2^(n-1)-x-1)
}

int main(){
	FAST_IO;
	int T;
	cin>>T;
	while(T--){
		int n,h,o;
		cin>>n>>h>>o;
		h--,o--;
		pll p1=cal(n,h),p2=cal(n,o);
		double x=p1.first-p2.first,y=p1.second-p2.second;
		printf("%.0f\n",sqrt(x*x+y*y)*10);
	}
	return 0;
} 
