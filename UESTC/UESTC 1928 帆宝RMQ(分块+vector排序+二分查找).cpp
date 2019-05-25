#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e6+5;
const int M=1e3+5;
const int INF=0x3f3f3f3f;

struct node{
	LL num;
	int id;
};

bool cmp1(node a,node b){
	return a.num==b.num?a.id<b.id:a.num<b.num;
}

bool cmp2(node a,node b){
	return a.num<b.num;
}

int n,q,block,num;
int l[M],r[M],belong[N];
LL arr[N],lazy[M];
vector<node>v[M];

void change(int x,int y,vector<node>&v){
	v.clear();
	rep(i,x,y)
		v.push_back(node{arr[i],i});
	sort(v.begin(),v.end(),cmp1);
}

void build(){
	block=sqrt(n);
	num=n/block+n%block;
	rep(i,1,num)
		l[i]=(i-1)*block+1,r[i]=i*block;
	rep(i,1,n)
		belong[i]=(i-1)/block+1;
	rep(i,1,num)
		change(l[i],r[i],v[i]);
}

void update(int x,int y,int add){
	if(belong[x]==belong[y]){
		int id=belong[x];
		rep(i,x,y) arr[i]+=add;
		change(l[id],r[id],v[id]);
		return;
	}
	int idx=belong[x],idy=belong[y];
	rep(i,x,r[idx]) arr[i]+=add;
	change(l[idx],r[idx],v[idx]);

	rep(i,idx+1,idy-1) lazy[i]+=add;

	rep(i,l[idy],y) arr[i]+=add;
	change(l[idy],r[idy],v[idy]);
}

//注意这里的pos不是实际位置，所以要记录原本的位置即id
int query(int x){
	int p1=-1,p2=-1;
	rep(i,1,num){
		int pos=lower_bound(v[i].begin(),v[i].end(),node{x-lazy[i],-1},cmp2)-v[i].begin();
		if(pos==v[i].size()||v[i][pos].num!=x-lazy[i]) continue;
		if(p1==-1) p1=v[i][pos].id;
		p2=v[i][pos].id;
		pos=upper_bound(v[i].begin(),v[i].end(),node{x-lazy[i],-1},cmp2)-v[i].begin();
		pos--;
		if(pos<0||v[i][pos].num!=x-lazy[i]) continue;
		p2=v[i][pos].id;
	}
	if(p1==-1)
		return -1;
	return p2-p1;
}

int main(){
	FAST_IO;
	cin>>n>>q;
	rep(i,1,n) cin>>arr[i];
	build();
	rep(i,1,q){
		int op,l,r,x;
		cin>>op;
		if(op==1){
			cin>>l>>r>>x;
			update(l,r,x);
		}
		if(op==2){
			cin>>x;
			cout<<query(x)<<endl;
		}
	}
	return 0;
}

