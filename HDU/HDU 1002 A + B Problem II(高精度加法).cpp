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
		tran(a2,s2);//���ַ���ת����������飻 
		for(;l1>=0||l2>=0;){
			if(l1<0)
				c[k]=c[k]+a2[l2--];//����l2--��ʼ������ 
			else if(l2<0)
				c[k]=c[k]+a1[l1--];//����l1--��ʼ������ 
			else 
				c[k]=c[k]+a1[l1--]+a2[l2--];
			if(c[k]>=10){
				c[k+1]=c[k]/10; 
				c[k]=c[k]%10;
			}
			k++; 
		}
		if(c[k]==0)
			k=k-1;//ȥ����ͷ���ܳ��ֵ�0 
		printf("Case %d:\n%s + %s = ",i,s1,s2);
		for(j=k;j>=0;j--)
				printf("%d",c[j]);
		if(i!=n)
			printf("\n\n");
		else
			printf("\n");
	}
} 
/*�������¼�������
  1���ҿ�ʼû�����λ����ͬ�������ʹλ��С����ǰ��λ����Ķ��䣬����123+12��ͬ��123+120�� 
  2��Ϊ��ʹλ����׼ĩβ����ʹ��l1--,l2--�ⲽ��ʱ�����ǰ�ǰ��ͳһ��ôд�ˣ�
*/ 
