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
		if(a[i]-a[i-1]<=1){//两条边相差不超过1，就可以先确定 
			temp*=a[i-1];//因为a[i-1] <=a[i]所以选小的边的长度 
			count++;//记录边数，count=2时说明找到四条边 
			i--;
		}
		if(count==2){
			ans+=temp;//ans记录形成的矩形面积 
			temp=1;
			count=0;
		}
	}
	printf("%lld\n",ans);
}
