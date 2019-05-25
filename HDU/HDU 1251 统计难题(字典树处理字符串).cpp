#include<stdio.h>
#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
struct node{
	node *next[26];
	int cnt;
	node(){
		for(int i=0;i<26;i++){
			next[i]=NULL;
		}
		cnt=0;
	}
};
node *p,*root=new node;
void insert(char *s){
	p=root;
	for(int i=0;s[i]!='\0';i++){
		int k=s[i]-'a';
		if(p->next[k]==NULL){
			p->next[k]=new node;
		}
		p=p->next[k];
		p->cnt++;
	}
}

int find(char *s){
	p=root;
	for(int i=0;s[i]!='\0';i++){
		int k=s[i]-'a';
		if(p->next[k]==NULL)
			return 0;
		p=p->next[k];
	}
	return p->cnt;
}

void del(node *root){
	for(int i=0;i<26;i++){
		if(root->next[i]!=NULL)
			del(root->next[i]);
	}
	delete(root);
}

int main(){
	char s[30];
	while(gets(s)){
		if(strlen(s)==0)
			break;
		insert(s);
	}
	while(gets(s)){
		printf("%d\n",find(s));
	}
	del(root);
}
