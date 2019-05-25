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
const int INF=0x3f3f3f3f;

int n,m;
int fa[N],val[N];

void init(){
	rep(i,0,n) fa[i]=i;
	memset(val,0,sizeof(val));
}

int find(int x){
	int tmp=fa[x];
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	val[x]=(val[x]+val[tmp])%3;
	return fa[x];
}

int main(){
	FAST_IO;
	cin>>n>>m;
	init();
	int ans=-1;
	rep(i,1,m){
		int op,x,y;
		cin>>op>>x>>y;
		if(ans!=-1) continue;
		int t1=find(x),t2=find(y);	
		if(t1==t2){
			if((val[x]+op-1)%3!=val[y])
				ans=i%3;
			continue;
		}
		fa[t2]=t1;
		val[t2]=(val[x]-val[y]+op-1+3)%3;//val[t2]+val[y]=val[x]+op-1即通过val[t2]值来满足这个关系 
	}
	if(ans==0)
		cout<<3<<endl;
	else
		cout<<ans<<endl;
	return 0;
}

