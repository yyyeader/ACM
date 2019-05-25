//1、一行不超过80个字符 
//2、数字、字母、标点算在一起 
#include<stdio.h>
#include<string.h>
int main(){
	char s[1005];
	int cnt=0;
	while(~scanf("%s",s)){
		if(strcmp(s,"<br>")==0){
			cnt=0;
			printf("\n");
		}
		else if(strcmp(s,"<hr>")==0){
			if(cnt)
				printf("\n--------------------------------------------------------------------------------\n");
			else
				printf("--------------------------------------------------------------------------------\n");
			cnt=0; 
		}
		else{
			if(cnt==0){
				cnt=strlen(s);//开头单词前面不需要空格 
				printf("%s",s);
			}
			else if(strlen(s)+cnt+1>80){
				printf("\n%s",s);
				cnt=strlen(s);
			}
			else{
				cnt+=strlen(s)+1;//注意还有个空格也要算在长度里 
				printf(" %s",s);//这样可以保证结尾不会多空格 
			}	
		}
	}
	printf("\n");
} 
