#include<stdio.h>
#include<string.h>
int main(){
	char s[1005];
	int i,j,k,n,l; 
	scanf("%d",&n);
	getchar();//���ջ��з� 
	while(n--){
		gets(s);
		l=strlen(s);
		for(i=0;i<=l;i++){
			if(s[i]==' '||i==l){//�����ո�������ַ���ĩβʱ���������ǰһ�����ַ��� 
				for(j=i-1;j>=0&&j!=k;j--)//������һ���ո�ʱ��k��û��ֵ��һֱ�����ͷ��j>=0;�����������������һ���ո�ǰΪֹ 
					printf("%c",s[j]);
				k=i;//��¼��һ���ո��λ�� 
				if(i!=l)
					printf(" ");//����������һ���ַ��������һ���ո�
			}	
		}
		printf("\n");
	}
}
