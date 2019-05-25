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

//01���� 
void ZeroOnePack(int value,int weight){
	for(int i=V;i>=weight;i--){
		dp[i]=max(dp[i],dp[i-weight]+value);
	}
}
//��ȫ����
void CompletePack(int value,int weight){
	for(int i=weight;i<=V;i++){
		dp[i]=max(dp[i],dp[i-weight]+value);
	}
}
//���ر���
void MultiplePack(int num,int value,int weight){
	//��������Ʒ����������������������Ϊȡ����������ȫ����
	if(num*weight>=V){
		CompletePack(value,weight);
		return;
	}
	//���С�������������ö�����+01�������� 
	else{
		int k=1;
		//���ģ����ö����ƣ�������num��ֳ����ɸ���ͬ���������ĺ� 
		while(k<=num){
			ZeroOnePack(k*value,k*weight);
			num-=k;
			k<<=1;//������һλ���൱�ڳ�2 
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
