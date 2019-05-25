#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

const int N=100005;
int dp[N];
int V;
struct node{
	int value,num;
}a[N];

//01背包 
void ZeroOnePack(int value,int weight){
	for(int i=V;i>=weight;i--){
		dp[i]=max(dp[i],dp[i-weight]+value);
	}
}
//完全背包
void CompletePack(int value,int weight){
	for(int i=weight;i<=V;i++){
		dp[i]=max(dp[i],dp[i-weight]+value);
	}
}
//多重背包
void MultiplePack(int num,int value,int weight){
	//如果这个物品容量大于总容量，可以认为取不尽，用完全背包
	if(num*weight>=V){
		CompletePack(value,weight);
		return;
	}
	//如果小于总容量，利用二进制+01背包处理 
	else{
		int k=1;
		//核心：利用二进制，把数量num拆分成若干个不同二进制数的和 
		while(k<=num){
			ZeroOnePack(k*value,k*weight);
			num-=k;
			k<<=1;//向左移一位，相当于乘2 
		}
		ZeroOnePack(num*value,num*weight);
	}
	return;
}

int main(){
	int i,j,n,k,sum;
	while(cin>>n&&n>0){
		sum=0;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++){
			cin>>a[i].value>>a[i].num;
			sum+=a[i].value*a[i].num;
		}
		V=sum/2;
		for(i=0;i<n;i++){
			MultiplePack(a[i].num,a[i].value,a[i].value);
		}
		cout<<sum-dp[V]<<" "<<dp[V]<<endl;
	}
} 
