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

char s[1005];
int mp[1005];

struct node{
	int num;//ÆµÂÊ 
	node *lc,*rc;
	node(){}
	node(int num){
		lc=rc=NULL;
		this->num=num;
	}
};

struct cmp{
	bool operator () (const node *a,const node *b){
		return a->num>b->num;
    }
};

int huffman(){
	;
}

int cal(node *root,int dep){
	if(root->lc==NULL&&root->rc==NULL) return root->num*dep;
	return cal(root->lc,dep+1)+cal(root->rc,dep+1);
}

int main(){
	while(~scanf("%s",s)){
		if(strcmp(s,"END")==0) break;
		memset(mp,0,sizeof(mp));
		int len=strlen(s);
		sort(s,s+len);
		s[len+1]='#';
		priority_queue<node*,vector<node*>,cmp >q;
		int cnt=1,idx=0;
		for(int i=1;i<=len;i++){
			if(s[i]!=s[i-1]){
				mp[idx++]=cnt;
				cnt=0;
			}
			cnt++;
		}
		for(int i=0;i<idx;i++){
			node *t=new node(mp[i]);
			q.push(t);
		}
		int sum=0;
		while(q.size()>1){
			node *t1=q.top();q.pop();
			node *t2=q.top();q.pop();
			node *t3=new node(t1->num+t2->num);
			t3->lc=t1;
			t3->rc=t2;
			q.push(t3);
		}
		node *root=q.top();q.pop();
		sum=cal(root,0);
		if(sum==0) sum=len;
		printf("%d %d %.1f\n",len*8,sum,8.0*len/sum);
	}
	return 0;
}

