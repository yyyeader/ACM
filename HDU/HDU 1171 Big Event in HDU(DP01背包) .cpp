/*��Ϊ��ĿҪ��Ҫ����ƽ�����䣬�������ǿ����Ƚ��ܼ�ֵsum�����Ȼ��ó�������ƽ��ֵΪsum/2,
Ҫע������𰸿���ΪС������������Ϊsum���������������ó���sum/2��ҪС�ڵ���ʵ�ʵ�ֵ������
���������01,���������Եó�����һ���������õ�����ֵ������һ�����������ֵҲ������Ӧ�ĵõ���
��ǰ�߱ض�С�ڵ��ں��ߡ�*/
#include<iostream>
#include<cstring> 
using namespace std;

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int i,j,n,value,amount,sum,count;
	int dp[500005],a[5005];
	while(cin>>n&&n>0){
		count=sum=0;
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++){
			cin>>value>>amount;
			while(amount--){
				a[count++]=value;
				sum+=value;
			}
		}
		
		for(i=0;i<count;i++){
			for(j=sum/2;j>=a[i];j--){
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
			}
		} 
		cout<<sum-dp[sum/2]<<' '<<dp[sum/2]<<endl;
		
	}
	return 0;
}
