#include<iostream>
using namespace std;

int main(){
	long long ts,tf,t,n,a,ans,m=1e12+5;//��Ϊ��������10^12������m��ʼ��Ϊ1e12+5 
	cin>>ts>>tf>>t>>n;
	while(n--){
		cin>>a;
		if(a&&a+t<=tf){//���������Ŷ�ʱ���ڽ���ʱ��֮��Ͳ����� 
			if(max(ts,a)+t<=tf&&ts-a+1<m){//ta-a+1��Ҫ�Ŷӵ�ʱ�䣬m����С����ʱ��
				m=ts-a+1,ans=min(ts,a-1);//min����ν���𰸲�Ψһ��a-1��ta��ȡһ��������
			}
			ts=max(ts,a)+t;//��һ���ŵ���ʱ��
		}
	}
	if(ts+t<=tf)//���ǵ������ܲ��뵽�Ŷӵ������Ų�������� 
		ans=ts;
	cout<<ans<<endl;
	return 0; 
}
