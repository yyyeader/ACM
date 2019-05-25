#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=15;
const int M=1e6+5;
int a[N];
int dp[M];

void bb(int V,int val){
	for(int j=V;j>=val;j--){
		if(dp[j-val])
			dp[j]=1;
	}
}

int main(){
	int cas=0;
	while(cin>>a[1]){
		memset(dp,0,sizeof(dp));
		for(int i=2;i<=6;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=1;i<=6;i++){
			sum+=a[i]*i;
		}
		if(!sum)
			break;	
		if(sum%2){
			cout<<"Collection #"<<++cas<<":"<<endl;
			cout<<"Can't be divided."<<endl<<endl;
			continue;
		}
		
		dp[0]=1;
		for(int i=1;i<=6;i++){
			if(a[i]==0) continue;
			int t=1;
			while(a[i]>=t){
				a[i]-=t;
				bb(sum/2,t*i);
				t<<=1;
			}
			bb(sum/2,a[i]*i);
		}
		
		if(dp[sum/2]){
			cout<<"Collection #"<<++cas<<":"<<endl;
			cout<<"Can be divided."<<endl<<endl;
		}
		else{
			cout<<"Collection #"<<++cas<<":"<<endl;
			cout<<"Can't be divided."<<endl<<endl;
		}
	}
	return 0;
}

