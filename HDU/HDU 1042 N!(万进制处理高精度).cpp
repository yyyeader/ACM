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
				}//һ������Ԫ�ش洢��λ������һλ��ģ������� 
				if(temp>0){
					a[++count]+=temp;
				}                                               
			}
			printf("%d",a[count]);//��λֱ����� 
			for(int i=count-1;i>=0;i--){
				printf("%04d",a[i]);//����������������λ��0���룬%04d����������Զ���0��������λ�� 
			}
			printf("\n");
		}
	}
}
