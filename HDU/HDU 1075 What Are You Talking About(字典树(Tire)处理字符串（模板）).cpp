#include<iostream>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

struct node{
	char *cc;
	node *next[26];
	int flag;
	node(){//��ʼ�� 
		for(int i=0;i<26;i++){
			next[i]=NULL;
		}
		flag=0;
	}
};

node *p,*root=new node;
void Insert(char *s,char *t){//1*�Ի����Ľ��н����������һ���ַ�������¶�Ӧ��Ӣ���ַ��� 
	p=root;
	for(int i=0;s[i]!='\0';i++){//��ʼ��д��i<26�� 
		int k=s[i]-'a';
		if(p->next[k]==NULL)
			p->next[k]=new node;
		p=p->next[k];
	}
	p->flag=1;//������ǵ�ǰ�����ַ����Ľ�β�ж�Ӧ��Ӣ���ַ���
	p->cc=(char *)malloc((strlen(t)+1)*sizeof(char));//���붯̬�ռ�  
	strcpy(p->cc,t);//����Ӧ�ַ������� 
}

void Search(char *s){//2*���� 
	p=root;
	if(strlen(s)==0)
		return;
	for(int i=0;s[i]!='\0';i++){//��ʼ��д��i<26�� 
		int k=s[i]-'a';
		if(p->next[k]==NULL){
			printf("%s",s);
			return;
		}
		p=p->next[k];
	}
	if(p->flag)
		printf("%s",p->cc);//����ҵ��Ķ�Ӧ�ĵ��� 
	else
		printf("%s",s);//�����ж��Ҳ������������ԭ����ĸ�����ȫ��������û�ж�Ӧ�ģ�
}

void del(node *root)//3*��̬������Ҫ�ͷ��ڴ� 
{
    for(int i=0;i<26;i++)
        if(root->next[i])
            del(root->next[i]);
    delete(root);
}
int main(){
	char ch1[3005],ch2[3005],temp[15];
	char ch;
	gets(temp);
	while(~scanf("%s",ch1)){
		if(strcmp(ch1,"END")==0) break;
		scanf("%s",ch2);
		Insert(ch2,ch1);
	}
	scanf("%s",temp);//��gets()�����һ�в�����'\n'���룬��scanf()��ֱ���������������뻻�з� 
	getchar();
	int k=0;
	while(gets(ch1)&&strcmp(ch1,"END")){//*������һ����һ��һ�������һ��һ�����봦��Ҫ�� 
		for(int i=0;ch1[i]!='\0';i++){
			if(islower(ch1[i])) temp[k++]=ch1[i];
			else{
				temp[k]='\0';k=0;
				Search(temp);
				putchar(ch1[i]);
			}
		}
		printf("\n"); 
	}
	del(root);
}

