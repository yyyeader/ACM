//1��һ�в�����80���ַ� 
//2�����֡���ĸ���������һ�� 
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
				cnt=strlen(s);//��ͷ����ǰ�治��Ҫ�ո� 
				printf("%s",s);
			}
			else if(strlen(s)+cnt+1>80){
				printf("\n%s",s);
				cnt=strlen(s);
			}
			else{
				cnt+=strlen(s)+1;//ע�⻹�и��ո�ҲҪ���ڳ����� 
				printf(" %s",s);//�������Ա�֤��β�����ո� 
			}	
		}
	}
	printf("\n");
} 
