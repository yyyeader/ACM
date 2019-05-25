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
const int N=2e5+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int l,r,sign,id;
};
vector<node>v;

int a[N],block;
LL cnt;
LL res[N],suml[N],sumr[N];//suml[i]表示1~l中i出现的次数，sumr[i]表示1~r中i出现的次数 

bool cmp(node a,node b){
	if(a.l/block==b.l/block) {
		if(a.l/block%2)
			return a.r<b.r;
		else
			return a.r>b.r;
	}
	return a.l/block<b.l/block;
}

int main(){
	FAST_IO;
	int n,m;
	cin>>n;
	block=sqrt(n);
	rep(i,1,n) cin>>a[i];
	cin>>m;
	rep(i,1,m){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		v.push_back(node{r1,r2,1,i});
		v.push_back(node{l1-1,r2,-1,i});
		v.push_back(node{l1-1,l2-1,1,i});
		v.push_back(node{r1,l2-1,-1,i});
	}
	sort(v.begin(),v.end(),cmp);
	int L=0,R=0;
	rep(i,0,(int)v.size()-1){
		//这里L,R加减的顺序与之前的模板不同，以第一个while()为例 
		//suml[a[L]]维护的是1~l前缀和,所以L++相当于扩大范围,所以先++(而之前的模板是减小范围) 
		//所以莫队中L,R加减顺序跟题目有关，不是固定的 
		while(L<v[i].l){
			L++;
			cnt+=sumr[a[L]];
			suml[a[L]]++;
		}
		while(L>v[i].l){
			cnt-=sumr[a[L]];
			suml[a[L]]--;
			L--;
		}
		while(R<v[i].r){
			R++;
			cnt+=suml[a[R]];
			sumr[a[R]]++;
		}
		while(R>v[i].r){
			cnt-=suml[a[R]];
			sumr[a[R]]--;
			R--;
		}
		res[v[i].id]+=v[i].sign*cnt;
	}
	rep(i,1,m) cout<<res[i]<<endl;
	return 0;
}

