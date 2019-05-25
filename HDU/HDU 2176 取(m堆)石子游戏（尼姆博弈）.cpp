#include<cstdio>
using namespace std;
const int N=2e5+5;

int a[N];

int main(){
	int m;
	while(~scanf("%d",&m)&&m){
		int sum=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			sum^=a[i];
		}
		bool flag=false;
		for(int i=1;i<=m;i++){
			sum^=a[i];
			if(sum<a[i]){
				if(!flag){
					printf("Yes\n");
					flag=true;
				}
				printf("%d %d\n",a[i],sum);	
			}
			sum^=a[i];
		}
		if(!flag)
			printf("No\n");
	}
	return 0;
} 
