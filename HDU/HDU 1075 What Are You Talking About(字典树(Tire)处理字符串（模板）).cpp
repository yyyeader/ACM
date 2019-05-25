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
	node(){//初始化 
		for(int i=0;i<26;i++){
			next[i]=NULL;
		}
		flag=0;
	}
};

node *p,*root=new node;
void Insert(char *s,char *t){//1*对火星文进行建树，在最后一个字符下面存下对应的英文字符串 
	p=root;
	for(int i=0;s[i]!='\0';i++){//开始错写成i<26了 
		int k=s[i]-'a';
		if(p->next[k]==NULL)
			p->next[k]=new node;
		p=p->next[k];
	}
	p->flag=1;//用来标记当前火星字符串的结尾有对应的英文字符串
	p->cc=(char *)malloc((strlen(t)+1)*sizeof(char));//申请动态空间  
	strcpy(p->cc,t);//将对应字符串存下 
}

void Search(char *s){//2*查找 
	p=root;
	if(strlen(s)==0)
		return;
	for(int i=0;s[i]!='\0';i++){//开始错写成i<26了 
		int k=s[i]-'a';
		if(p->next[k]==NULL){
			printf("%s",s);
			return;
		}
		p=p->next[k];
	}
	if(p->flag)
		printf("%s",p->cc);//输出找到的对应的单词 
	else
		printf("%s",s);//特殊判断找不到的情况，把原有字母输出（全部找完仍没有对应的）
}

void del(node *root)//3*动态建树后要释放内存 
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
	scanf("%s",temp);//用gets()会把上一行残留的'\n'输入，而scanf()会直接跳过，不能输入换行符 
	getchar();
	int k=0;
	while(gets(ch1)&&strcmp(ch1,"END")){//*先输入一行在一个一个处理比一个一个输入处理要快 
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

