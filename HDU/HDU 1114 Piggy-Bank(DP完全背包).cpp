#include<iostream>
#include<cstring>
const int inf=1<<30;
using namespace std;

int min(int a,int b){
	return a<b?a:b; 
} 
int main(){
	int j,i,n,q,tm1,tm2,cap,value,weight;
	int dp[10005];
	cin>>q;
	while(q--){
		memset(dp,0,sizeof(dp));
		cin>>tm1>>tm2;
		cap=tm2-tm1;
		cin>>n;
		for(i=1;i<=cap;i++)
			dp[i]=inf;//��ΪҪ����Сֵ���ȳ�ʼ��Ϊ���޴� 
		for(i=1;i<=n;i++){
			cin>>value>>weight;
			for(j=weight;j<=cap;j++){//��01������ͬ�ľ���j��weight��cap,����01������j��cap��weight
				dp[j]=min(dp[j],dp[j-weight]+value);
			}
		}
		if(dp[cap]==inf)
			cout<<"This is impossible."<<endl;
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[cap]<<"."<<endl;
	} 
}
