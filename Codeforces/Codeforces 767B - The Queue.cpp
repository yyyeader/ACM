#include<iostream>
using namespace std;

int main(){
	long long ts,tf,t,n,a,ans,m=1e12+5;//因为最大的数是10^12，所以m初始化为1e12+5 
	cin>>ts>>tf>>t>>n;
	while(n--){
		cin>>a;
		if(a&&a+t<=tf){//如果这个人排队时间在结束时间之后就不管他 
			if(max(ts,a)+t<=tf&&ts-a+1<m){//ta-a+1是要排队的时间，m是最小消耗时间
				m=ts-a+1,ans=min(ts,a-1);//min无所谓，答案不唯一，a-1、ta任取一个都可以
			}
			ts=max(ts,a)+t;//下一次排到的时间
		}
	}
	if(ts+t<=tf)//考虑到，可能插入到排队的人里排不到的情况 
		ans=ts;
	cout<<ans<<endl;
	return 0; 
}
