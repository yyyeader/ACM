//1��spaces(' '), tabs('\t'), or enters('\n')  Presentation Error
//2��Wrong Answer 
#include<stdio.h>
#include<string.h>
const int N=5050;
char a1[N],b1[N],a2[N],b2[N],temp[N]; 
void input(char a[],char b[]){
	int i,count=0;
	gets(temp);//ȥ��START���� 
	while(gets(temp)!=NULL){
		if(strcmp(temp,"END")==0) break;
		strcat(a,temp);//��ÿ�е��ַ����ŵ�һ��������
		strcat(a,"\n");//ÿ�н������л��з�
	}
	for(i=0;i<strlen(a);i++){
		if(a[i]!=' '&&a[i]!='\t'&&a[i]!='\n')
			b[count++]=a[i];
	}
	b[count]='\0';//b�����൱������a��ȥ����' '��'\t'��'\n'����ַ�����
}
int main(){
	 int n;
	 scanf("%d",&n);
	 getchar();
	 while(n--){
	 	a1[0]='\0';
	 	a2[0]='\0';
	 	input(a1,b1);
	 	input(a2,b2);
	 	if(strcmp(a1,a2)==0) printf("Accepted\n");
	 	else if(strcmp(b1,b2)==0) printf("Presentation Error\n");
	 	else printf("Wrong Answer\n");
	 }
} 
