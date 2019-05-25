#include<iostream>
#include<queue>
#include<string>
using namespace std;
int a[10005];
int b[10005];
int flag=1;
int index=0;
struct node{
    int num;
    node *left;
    node *right;
};
 
void insert(node *T,node *t){
    if(t->num<T->num){
        if(T->left==NULL){
            T->left=t;
            t->left=t->right=NULL;
        }   
        else
            insert(T->left,t);
    }
    else{
        if(T->right==NULL){
            T->right=t;
            t->left=t->right=NULL;
        }
        else
            insert(T->right,t);
    }
}
 
void print(node *T){
    a[++index]=T->num;
    if(T->left!=NULL)
        print(T->left);
    if(T->right!=NULL)
        print(T->right);
}
void print1(node *T){
	b[++index]=T->num;
	if(T->left!=NULL)
        print1(T->left);
    if(T->right!=NULL)
        print1(T->right);
}
//后序 
void print2(node *T){
    if(T->left!=NULL)
        print2(T->left);
    if(T->right!=NULL)
        print2(T->right);
    a[++index]=T->num;
}
//层次遍历 
void print3(node *T){
	queue<node *>q;
	node *pre=NULL,*now=NULL;
	q.push(T);
    while(!q.empty()){
 		 pre=q.front();
		 q.pop();
		 b[++index]=pre->num; 
		 if(pre->left!=NULL)	q.push(pre->left);
		 if(pre->right!=NULL)	q.push(pre->right);       
    }
}
 
int main(){
    int n;
    node *T1=NULL,*T2=NULL;
    T1=new node;
    cin>>n;
	for(int i=1;i<=n;i++){
        if(i==1){
            cin>>T1->num;
            T1->left=T1->right=NULL;
        }
        else{
            node *p=new node;
            cin>>p->num;
            insert(T1,p);
        }       
    }
    T2=new node;
	for(int i=1;i<=n;i++){ 
        if(i==1){
            cin>>T2->num; 
            T2->left=T2->right=NULL;
        }
        else{
            node *p=new node;
            cin>>p->num;
            insert(T2,p);
        } 	    
    }
    print(T1);
	index=0;
    print1(T2);
    for(int i=1;i<=n;i++){
    	if(a[i]!=b[i]){
    		flag=0;
    		break;
		}
	}
    if(flag)
        cout<<"YES"<<endl;
    else 
    	cout<<"NO"<<endl;
    //后序 
    index=0;
    print2(T1);
    //层次遍历 
    index=0;
    print3(T1);
    for(int i=1;i<=n;i++)
    	cout<<a[i]<<(i!=n?' ':'\n');
    for(int i=1;i<=n;i++)
    	cout<<b[i]<<(i!=n?' ':'\n');
    return 0;
}
