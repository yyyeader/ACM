#include<stdio.h>
#include<string.h>
#define N 10005
void tran(int a[],char s[]){
	int i;
	for(i=0;s[i]!='\0';i++){
		a[i]=s[i]-'0';
	}
}
int main(){
	char s1[N],s2[N];
	int a1[N],a2[N],c[N];
	int n,i,j,k,l1,l2;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s %s",&s1,&s2);
		k=0;
		memset(c,0,sizeof(c));
		l1=strlen(s1)-1;
		l2=strlen(s2)-1;
		tran(a1,s1);
		tran(a2,s2);//将字符串转变成数字数组； 
		for(;l1>=0||l2>=0;){
			if(l1<0)
				c[k]=c[k]+a2[l2--];//这里l2--开始忘加了 
			else if(l2<0)
				c[k]=c[k]+a1[l1--];//这里l1--开始忘加了 
			else 
				c[k]=c[k]+a1[l1--]+a2[l2--];
			if(c[k]>=10){
				c[k+1]=c[k]/10; 
				c[k]=c[k]%10;
			}
			k++; 
		}
		if(c[k]==0)
			k=k-1;//去除开头可能出现的0 
		printf("Case %d:\n%s + %s = ",i,s1,s2);
		for(j=k;j>=0;j--)
				printf("%d",c[j]);
		if(i!=n)
			printf("\n\n");
		else
			printf("\n");
	}
} 
/*犯了以下几个错误：
  1、我开始没处理好位数不同的情况，使位数小的向前跟位数大的对其，导致123+12等同于123+120； 
  2、为了使位数对准末尾，在使用l1--,l2--这步的时候忘记把前面统一这么写了；
*/ 
