#include<cstdio>
int a[105];

int main(){
	int n;
	while(scanf("%d",&n)&&n){
		int sum=0;//a[1]~a[n]µÄÒì»òÖµ 
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum^=a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			sum^=a[i];//a^b^b=a^0=a 
			if(sum<a[i])
				ans++;
			sum^=a[i];
		}
		printf("%d\n",ans);
	}
} Being a Good Boy in Spring Festival
