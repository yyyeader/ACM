#include<stdio.h>
#include<string.h>
//�����ؼ��ǿ��Բ���ת����10��������ֱ�ӽ���26������ӣ�
//��ȥ����'A'�Ĳ��֣��Լ��������߶�ֻ��'A'�ַ���ʱ��Ҫ���'A'; 
int main(){
	char s1[205];
	char s2[205];
	int  c[205];
	int l1,l2,l,i,j,k;
	while(~scanf("%s %s",s1,s2)){
		l1=strlen(s1)-1;
		l2=strlen(s2)-1;
		memset(c,0,sizeof(c));
		k=0;
		for(;l1>=0||l2>=0;l1--,l2--){
			if(l1<0)
				c[k]+=s2[l2]-'A'; 
			else if(l2<0)
				c[k]+=s1[l1]-'A';
			else
				c[k]+=s1[l1]+s2[l2]-2*'A';//������'+'���ˣ��ҵ����ӡ����� 
			if(c[k]>=26){
				c[k+1]+=c[k]/26;
				c[k]%=26;
			}
			k++;
		}
		for(;k>=0;k--){
			if(c[k]!=0)
				break;
		}
		if(c[0]==0)
			printf("A");
		for(j=k;j>=0;j--){
			printf("%c",c[j]+'A');
		}
		printf("\n");
	}
	return 0;
}

