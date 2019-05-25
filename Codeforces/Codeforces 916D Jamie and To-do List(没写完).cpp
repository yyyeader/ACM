#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define INF 0x3f3f3f3f
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FOR(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=1e5+5;

struct node{
	char op[20],s[20];
	int d;
}arr[N];

struct Node{
	char op[20],s[20];
	int d;
	Node(){}
	Node(char *op,char *s,int d){
		strcpy(this->op,op);
		strcpy(this->s,s);
		this->d=d;
	}
}brr[N];

struct node2{
	LL sum,add;
	int l,r;
}tree[N*4];

LL ans;
int Hash[N];
map<string,int>mp;
map<string,bool>exist;

void pushup(int p){
	tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
}

void pushdown(int p){
	tree[LC(p)].sum+=tree[p].add*(tree[LC(p)].r-tree[LC(p)].l+1);
	tree[RC(p)].sum+=tree[p].add*(tree[RC(p)].r-tree[RC(p)].l+1);
	tree[LC(p)].add+=tree[p].add;
	tree[RC(p)].add+=tree[p].add;
	tree[p].add=0;
}

void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].add=0;
	if(l==r){
		tree[p].sum=0;
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
	pushup(p);
}

void update(int p,int l,int r,int add){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		tree[p].sum+=add*(tree[p].r-tree[p].l+1);
		tree[p].add+=add;	
		return;
	}
	pushdown(p);
	update(LC(p),l,r,add);
	update(RC(p),l,r,add);
	pushup(p);
}

void query(int p,int l,int r){
	if(l>tree[p].r||r<tree[p].l)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		ans+=tree[p].sum;
		return;	
	}
	pushdown(p);
	query(LC(p),l,r);
	query(RC(p),l,r);
}

int bin_search(int l,int r,int x){
    while(l<=r){
        int mid=(l+r)/2;
        if(Hash[mid]==x)
            return mid;
        else if(Hash[mid]<x)
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}

int main(){
	int n,m=0;
	char op[25],s[25];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",arr[i].op);
		if(strcmp("set",arr[i].op)==0){
			scanf("%s%d",&arr[i].s,&arr[i].d);
			Hash[++m]=arr[i].d;
		}
		else if(strcmp("query",arr[i].op)==0){
			scanf("%s",&arr[i].s);
			arr[i].d=-1;
		}
		else if(strcmp("remove",arr[i].op)==0){
			scanf("%s",arr[i].s);
			arr[i].d=-1;
		}
		else
			scanf("%d",&arr[i].d);
	}
	sort(Hash+1,Hash+1+m);
	m=unique(Hash+1,Hash+1+m)-(Hash+1);
	int cnt=0;
	for(int i=n;i>=1;i--){
		if(strcmp("undo",arr[i].op)==0)
			i-=arr[i].d;
		else
			brr[++cnt]=Node(arr[i].op,arr[i].s,bin_search(1,m,arr[i].d));	
	}
	build(1,1,m);
	
	for(int i=cnt;i>=1;i--){
		if(strcmp("set",brr[i].op)==0){
			if(mp.find(brr[i].s)==mp.end()){
				mp[brr[i].s]=brr[i].d;
				exist[brr[i].s]=true;
				if(brr[i].d<m)
					update(1,brr[i].d+1,m,1);
			}
			else if(!exist[brr[i].s]){
				mp[brr[i].op]=brr[i].d;
				exist[brr[i].op]=true;
				if(brr[i].d<m)
					update(1,brr[i].d+1,m,1);
			}
			else{
				int tmp=mp[brr[i].s];
				mp[brr[i].s]=brr[i].d;
				if(brr[i].d>tmp){
					update(1,tmp+1,brr[i].d,-1);
				}
				else if(brr[i].d<tmp){
					update(1,brr[i].d+1,tmp,1);
				}
			}
		}
		else if(strcmp("query",brr[i].op)==0){
			ans=0;
			if(!exist[brr[i].s])
				ans=-1;
			else if(mp[brr[i].s]>1)
				query(1,mp[brr[i].s],mp[brr[i].s]);
			printf("%lld\n",ans);
		}
		else if(strcmp("remove",brr[i].op)==0){
			exist[brr[i].s]=false;
			if(mp[brr[i].s]<m)
				update(1,mp[brr[i].s]+1,m,-1);
		}
	}
	return 0; 
}

