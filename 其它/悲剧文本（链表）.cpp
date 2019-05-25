#include<cstdio>
#include<malloc.h>
#include<iostream>
#define LEN sizeof(struct node)
using namespace std;
struct node{
    char ch;
    struct node *next;
};
 
struct node *creat(char *s){
    node *p1=NULL,*p2=NULL,*end=NULL,*head=NULL;//p1new£¬p2now,end
    p1=p2=(node *)malloc(LEN);
   	int sign=0;//1='[',2=']';
    for(int i=0;s[i]!='\0';i++){
        char x=s[i];
        if(x=='[')
            sign=1;
        else if(x==']')
            sign=2;
        else{
            p1->ch=x;
            if(head==NULL){
            	head=end=p2=p1;
            	head->next=NULL;
            	sign=2;
			}
            else if(sign==1){
                p1->next=head;
                head=p1;
                p2=p1;
                sign=0;
            }
            else if(sign==2){
                end->next=p1;
                end=p1;
                p2=end;
                end->next=NULL;
            }
            else if(sign==0){
            	p1->next=p2->next;
            	p2->next=p1;
            	p2=p1;
			}
            p1=(node *)malloc(LEN);
        }
    }
    free(p1);
    p1=NULL;
    return head;
}
 
int main(){
    char s[1005];
    while(~scanf("%s",s)){
        node *H=NULL,*p=NULL;
        H=creat(s);
        p=H;
        while(p!=NULL){
            printf("%c",p->ch);
            p=p->next;
        }
        printf("\n");
    }
} 

