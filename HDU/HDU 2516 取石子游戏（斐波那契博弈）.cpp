#include<cstdio>
typedef long long LL;
LL a[60]={0,1,2};

void fib(void){
	for(int i=3;i<=50;i++){
		a[i]=a[i-1]+a[i-2];
	}
} 

int main(){
	fib();
	int n;
	while(~scanf("%d",&n)&&n){	
		bool flag=true;
		for(int i=2;i<=50;i++){
			if(a[i]==n)
				flag=false;
		}
		if(flag)
			puts("First win");
		else
			puts("Second win");
	}
	return 0;
}
