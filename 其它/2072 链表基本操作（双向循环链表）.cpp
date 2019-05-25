#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e4+5;
int n;
int a[N];
struct node{
    int num;
    struct node *pre;
    struct node *next;
};

//普通插入,p1是t前面的点，p2是t后面的点 
void insert(node* p1,node *p2,node *t){
	n++;
	p1->next=t;
	t->pre=p1;
	p2->pre=t;
	t->next=p2;
}

//头j节点插入t
struct node *Top_insert(node *head,node *t){
	n++;
	if(head==NULL){
		head=t;
		head->pre=head->next=head;
	}
	else{
		head->pre->next=t;
		t->next=head;
		t->pre=head->pre;
		head->pre=t;
		head=t;
	}
	return head;
}
 
//普通删除
void *del(node *t){
	n--;
    t->pre->next=t->next;
	t->next->pre=t->pre;
	delete t;
}

//删除头节点t
struct node *Top_del(node *head,node *t){
	n--;
	t->pre->next=t->next;
	t->next->pre=t->pre;
	if(n>0)
		head=t->next;
	else
		head=NULL;
	delete t;
	return head; 
}

struct node *Pos_find(node *head,int pos){
	int cnt=0;
	struct node *p=head;
	while(++cnt){
		if(pos==cnt)
			return p;
		p=p->next;	
	}
}

//输出链表 
void print(node *head){
	struct node *p=head;
	int cnt=n;
	while(cnt--){
		if(cnt)
			printf("%d ",p->num);
		else
			printf("%d\n",p->num);
		p=p->next;
	}
}
//清空链表 
void clear(node *head,int len){
	if(len>n)
		return;
	clear(head->next,len+1);
	delete(head);
}

//创建链表 
struct node *creat(){
	struct node *p1=NULL,*p2=NULL,*p3=NULL,*head=NULL;
	p1=p2=new node;
	int len;
	scanf("%d",&len);
	//初始元素为0要注意 
	if(len==0)
		return head;
	for(int i=1;i<=len;i++)
		scanf("%d",&a[i]);
	for(int i=len;i>=1;i--){
		p1->num=a[i];
		if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p3=p2;
		p2=p1;
		p2->next=NULL;
		p2->pre=p3;
		p1=new node;
	}
	p2->next=head;
	head->pre=p2;
	n=len;
	return head;
}

int main(){
	struct node *H=NULL;
	H=creat();
	int m;
	scanf("%d",&m);
    while(m--){
		int x,pos;
		char op[10];
   		scanf("%s",op);	
		if(!strcmp(op,"insert")){
			scanf("%d%d",&pos,&x);
			struct node *p=NULL,*t=new node;
			t->num=x;
			if(n+1<pos)
				puts("insert fail");
			else{
				puts("insert OK");
				if(n==0)
					H=Top_insert(H,t);
				else{
					p=Pos_find(H,pos);
					if(p==H&&pos<=n)
						H=Top_insert(H,t);
					else
						insert(p->pre,p,t);
				}
			}
		}
		else if(!strcmp(op,"delete")){
			scanf("%d",&pos);
			struct node *p=NULL;	
			if(n<pos)
				puts("delete fail");
			else{
				puts("delete OK");
				p=Pos_find(H,pos);
				if(p==H)
					H=Top_del(H,p);
				else
					del(p);
			}
		}
		else if(!strcmp(op,"get")){
			scanf("%d",&pos);
			if(n<pos)
				puts("get fail");
			else
				printf("%d\n",Pos_find(H,pos)->num);
		}
		else{
			if(n==0)
				puts("Link list is empty");
			else
				print(H);
		}	
    }
    clear(H,1);
   return 0;
}
