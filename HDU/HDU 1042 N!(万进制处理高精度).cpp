#include<stdio.h>
#include<string.h>
#define N 10005
int main(){
	int n;
	int a[N],temp,count;
	while(~scanf("%d",&n)){
		if(n==0||n==1)
			printf("1\n");
		else{
			memset(a,0,sizeof(a));
			temp=count=0;
			a[count]=1;
			for(int i=2;i<=n;i++){
				temp=0;
				for(int j=0;j<=count;j++){
					a[j]=a[j]*i+temp;;
					temp=a[j]/10000;
					a[j]=a[j]%10000;
				}//一个数组元素存储四位数代表一位，模拟万进制 
				if(temp>0){
					a[++count]+=temp;
				}                                               
			}
			printf("%d",a[count]);//首位直接输出 
			for(int i=count-1;i>=0;i--){
				printf("%04d",a[i]);//接下来的数不足四位用0补齐，%04d可以在左边自动用0补齐至四位； 
			}
			printf("\n");
		}
	}
}
