#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=2e5+5;
const int INF=0x3f3f3f3f;

int n,block,num,arr[N],l[N],r[N],belong[N];//block是块的大小,num是块的数量,x[i]和y[i]分别是第i块的左右边界,belong[i]表示第i个元素所属的块 
int lazy[N];
vector<int>v[N];

void build(){
	block=sqrt(n);
	num=n/block;
	if(n%block) num++;
	rep(i,1,num)
		l[i]=(i-1)*block+1,r[i]=i*block;
	r[num]=n;
	rep(i,1,n)
		belong[i]=(i-1)/block+1;
	rep(i,1,n){
		int id=belong[i];
		v[id].push_back(arr[i]);
	}
	rep(i,1,num) sort(v[i].begin(),v[i].end());
}

void change(int x,int y,vector<int>&v){
	v.clear();
	rep(i,x,y) v.push_back(arr[i]);
	sort(v.begin(),v.end());
}

void update(int x,int y,int add){
	if(belong[x]==belong[y]){
		int id=belong[x];
		rep(i,x,y)	arr[i]+=add;
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

int query(int x,int y,int c){
	int ans=-1;
	if(belong[x]==belong[y]){
		int id=belong[x];
		rep(i,x,y){
			if(arr[i]+lazy[id]<c)
				ans=max(ans,arr[i]+lazy[id]);
		}
		return ans;
	}
	int idx=belong[x],idy=belong[y];
	rep(i,x,r[idx])
		if(arr[i]+lazy[idx]<c)
			ans=max(ans,arr[i]+lazy[idx]);
			
	rep(i,idx+1,idy-1){
		int pos=lower_bound(v[i].begin(),v[i].end(),c-lazy[i])-v[i].begin();
		if(pos==0) continue;
		ans=max(ans,v[i][--pos]+lazy[i]);
	}
	
	rep(i,l[idy],y)
		if(arr[i]+lazy[idy]<c)
			ans=max(ans,arr[i]+lazy[idy]);
	return ans;	
}

int main(){
	FAST_IO;
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&arr[i]);
	build();
	rep(i,1,n){
		int op,a,b,c;
		scanf("%d%d%d%d",&op,&a,&b,&c);
		if(op==0)
			update(a,b,c);
		if(op==1)
			printf("%d\n",query(a,b,c));
	}
	return 0;
}

