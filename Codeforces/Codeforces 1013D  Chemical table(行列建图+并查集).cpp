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
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int fa[N];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
	int n,m,q;
	cin>>n>>m>>q;
	rep(i,0,n+m) fa[i]=i;
	rep(i,1,q){
		int r,c;
		cin>>r>>c;
		int t1=find(r),t2=find(c+n);
		fa[t1]=t2;
	}
	int ans=0;
	rep(i,1,n+1+m){
		if(find(i)==i)
			ans++;
	}
	cout<<ans-1<<endl;
	return 0;
}

