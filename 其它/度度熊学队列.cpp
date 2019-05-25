#include<iostream>
#include<cstdio>
using namespace std;
const int N=4e5;

struct node{
	int num;
	node *next,*pre;
	node(){
		next=pre=NULL;
	}
};
node *head[N],*tail[N];
int n,q;

void del(node *head){
	if(head==NULL)
		return;
	del(head->next);
	delete head;
}

void init(){
	for(int i=1;i<=n;i++){
		del(head[i]);
		tail[i]=NULL;
	}
}

void add(int u,int w,int val){
	node *p=new node;
	p->num=val;
	if(head[u]==NULL){
		head[u]=tail[u]=p;
		return;
	}
	if(w==0){
		p->next=head[u];
		head[u]->pre=p;
		head[u]=p;
	}
	else{
		tail[u]->next=p;
		p->pre=tail[u];
		tail[u]=p;
	}
}

void delet(int u,int w){
	node *p=NULL;
	if(head[u]==NULL){
		puts("-1");
		return;
	}
	if(head[u]==tail[u]){
		printf("%d\n",head[u]->num);
		delete head[u];
		head[u]=tail[u]=NULL;
		return;
	}
	if(w==0){
		printf("%d\n",head[u]->num);
		p=head[u];
		head[u]=head[u]->next;
		head[u]->pre=NULL;
		delete p;
	}
	else{
		printf("%d\n",tail[u]->num);
		p=tail[u];
		tail[u]=tail[u]->pre;
		tail[u]->next=NULL;
		delete p;
	}
}

void link(int u,int v,int w){
	if(head[v]==NULL) return;
	if(w==0){
		tail[u]->next=head[v];
		head[v]->pre=tail[u];;
	}
	else{
		tail[u]->next=tail[v];
		tail[v]->pre=tail[u];
		head[v]->pre=tail[v]->pre;
		tail[v]->next=head[v]->next;
		head[v]->next=NULL;
	}
	head[v]=tail[v]=NULL;
}

int main(){
	while(~scanf("%d%d",&n,&q)){
		init();
		for(int i=1;i<=q;i++){
			int op,u,v,w,val;
			scanf("%d",&op);
			if(op==1){
				scanf("%d%d%d",&u,&w,&val);
				add(u,w,val);
			}
			if(op==2){
				scanf("%d%d",&u,&w);
				delet(u,w);
			}
			if(op==3){
				scanf("%d%d%d",&u,&v,&w);
				link(u,v,w);
			}
		}
	}
	return 0;
}
