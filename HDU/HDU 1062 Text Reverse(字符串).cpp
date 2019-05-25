#include<stdio.h>
#include<string.h>
int main(){
	char s[1005];
	int i,j,k,n,l; 
	scanf("%d",&n);
	getchar();//吸收换行符 
	while(n--){
		gets(s);
		l=strlen(s);
		for(i=0;i<=l;i++){
			if(s[i]==' '||i==l){//遇到空格或者在字符串末尾时，倒序输出前一个段字符串 
				for(j=i-1;j>=0&&j!=k;j--)//遇到第一个空格时，k还没有值，一直输出到头即j>=0;接下来都是输出到上一个空格前为止 
					printf("%c",s[j]);
				k=i;//记录上一个空格的位置 
				if(i!=l)
					printf(" ");//如果不是最后一段字符串就输出一个空格
			}	
		}
		printf("\n");
	}
}
