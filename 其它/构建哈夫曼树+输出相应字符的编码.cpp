#include <bits/stdc++.h>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

string ans[300];
string str;

struct node{
	int num;
	char ch;
	node *lc,*rc;
	node(int num){
		this->num=num;
		lc=rc=NULL;
	}
};

struct cmp{
	bool operator () (const node *a,const node *b)const{
		return a->num>b->num;
	}
};

priority_queue<node*,vector<node*>,cmp>q;

void print(node *root){
	if(root->lc==NULL&&root->rc==NULL){
		ans[root->ch]=str;
		return;
	}
	str+="0";
	print(root->lc);
	str=str.substr(0,str.length()-1);
	str+="1";
	print(root->rc);
	str=str.substr(0,str.length()-1);
}

void build_tree(){
	while(q.size()>1){
		node *t1=q.top();q.pop();
		node *t2=q.top();q.pop();
		node *t3=new node(t1->num+t2->num);
		t3->lc=t1;
		t3->rc=t2;
//		cout<<t3->num<<" "<<t1->num<<" "<<t2->num<<endl;
		q.push(t3);
	}
	node *root=q.top();q.pop();
	str="";
	for(int i=0;i<300;i++) ans[i]="";
	print(root);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char ch;
		int num;
		getchar();
		scanf("%c%d",&ch,&num);
		node *t=new node(num);
		t->ch=ch;
		q.push(t);
	}
	build_tree();
	for(int i=0;i<300;i++){
		if(ans[i].length()>0)
			cout<<char(i)<<" "<<ans[i]<<endl;
	}
	return 0;
}

