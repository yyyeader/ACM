#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[100005];
	int n,count;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	long long temp,ans;
	count=ans=0;
	temp=1;
	sort(a,a+n); 
	for(int i=n-1;i>=1;i--){
		if(a[i]-a[i-1]<=1){//������������1���Ϳ�����ȷ�� 
			temp*=a[i-1];//��Ϊa[i-1] <=a[i]����ѡС�ıߵĳ��� 
			count++;//��¼������count=2ʱ˵���ҵ������� 
			i--;
		}
		if(count==2){
			ans+=temp;//ans��¼�γɵľ������ 
			temp=1;
			count=0;
		}
	}
	printf("%lld\n",ans);
}
