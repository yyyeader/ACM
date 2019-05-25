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
			dp[i]=inf;//因为要求最小值，先初始化为无限大 
		for(i=1;i<=n;i++){
			cin>>value>>weight;
			for(j=weight;j<=cap;j++){//与01背包不同的就是j从weight到cap,而按01背包则j从cap到weight
				dp[j]=min(dp[j],dp[j-weight]+value);
			}
		}
		if(dp[cap]==inf)
			cout<<"This is impossible."<<endl;
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[cap]<<"."<<endl;
	} 
}
