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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int n,m;
int fa[N];
set<int>st[N];

void init(){
	rep(i,0,n) fa[i]=i;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
	FAST_IO;
	cin>>n>>m;
	init();
	rep(i,1,m){
		string op;
		int x,y,col;
		cin>>op>>x>>y;
		int t1=find(x),t2=find(y);
		if(op=="A"){
			cin>>col;
			if(col==1&&t1!=t2){
				//将小的往大的集合里合并 
				if(st[t1].size()>st[t2].size()) swap(t1,t2);
				fa[t1]=t2;
				for(auto it:st[t1]){
					st[t2].insert(find(it));	
				}
			}
			else{
				st[t1].insert(t2);
				st[t2].insert(t1);
			}
		}
		else{
			if(t1==t2)
				cout<<1<<endl;
			else if(st[t1].find(t2)!=st[t1].end()||st[t2].find(t1)!=st[t2].end())
				cout<<2<<endl;
			else
				cout<<3<<endl;
		}
	}
	return 0;
}

