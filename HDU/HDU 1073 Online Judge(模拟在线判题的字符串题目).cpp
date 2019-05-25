//1、spaces(' '), tabs('\t'), or enters('\n')  Presentation Error
//2、Wrong Answer 
#include<stdio.h>
#include<string.h>
const int N=5050;
char a1[N],b1[N],a2[N],b2[N],temp[N]; 
void input(char a[],char b[]){
	int i,count=0;
	gets(temp);//去掉START部分 
	while(gets(temp)!=NULL){
		if(strcmp(temp,"END")==0) break;
		strcat(a,temp);//把每行的字符都放到一个数组里
		strcat(a,"\n");//每行结束都有换行符
	}
	for(i=0;i<strlen(a);i++){
		if(a[i]!=' '&&a[i]!='\t'&&a[i]!='\n')
			b[count++]=a[i];
	}
	b[count]='\0';//b数组相当于数组a是去掉了' '、'\t'和'\n'后的字符串；
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
