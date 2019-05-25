#include<cstdio>
int a[50];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int sum=0,count=0;
		bool flag=false;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==1)
				count++; 
			sum^=a[i];
		}
		if(count==n)
			flag=(count%2==0);
		else 
			flag=(sum!=0);
		if(flag)
			printf("John\n");
		else
			printf("Brother\n");
	}
} 
