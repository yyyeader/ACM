/*因为题目要求要尽量平均分配，所以我们可以先将总价值sum求出，然后得出其分配的平均值为sum/2,
要注意这个答案可能为小数，但是又因为sum是整数，所以最后得出的sum/2是要小于等于实际的值。将这
个结果进行01,背包，可以得出其中一个宿舍所得的最大价值，而另一个宿舍的最大价值也可以相应的得到，
而前者必定小于等于后者。*/
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
