#include<stdio.h>
int a[1005][130];
int main(){
	int n,i,j;
	a[1][1]=1;
	a[2][1]=2; 
	a[3][1]=4;
	a[4][1]=7;
	for(i=5;i<=1000;i++){
		for(j=1;j<=130;j++){
			a[i][j]=a[i-1][j]+a[i-2][j]+a[i-4][j];//递推公式，好难- -、、、 
		}
		for(j=1;j<=130;j++){
			if(a[i][j]>=100000000){
				a[i][j+1]+=a[i][j]/100000000;
				a[i][j]%=100000000;
			}//满足八位数向前进一位 
		}
	}
	while(~scanf("%d",&n)){
		for(j=130;j>=1;j--){
			if(a[n][j]!=0)
				break;//消除多余的初始化时产生的0 
		}
		printf("%d",a[n][j]);
		for(j=j-1;j>=1;j--){
			printf("%08d",a[n][j]);//不足八位左边用0补齐 
		}
		printf("\n");
	}
}
 
