#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#pragma comment(linker, "/STACK:102400000,102400000")
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e6+5;
const int M=2e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int next,to;
}edge[M*2];

int cnt,n,m;
int head[4*N],deg[4*N],ans[4*N];
stack<int>sk;
bool vis[M*2];

void init(){
	cnt=2;
	ans[0]=0;
	memset(deg,0,sizeof(deg));
	memset(head,0,sizeof(head));
}

void add(int u,int v){
	edge[cnt]=node{head[u],v};
	head[u]=cnt++;
}

void print(int st){
	sk.push(st);
	while(!sk.empty()){
		int u=sk.top();sk.pop();
		ans[++ans[0]]=u;
		for(int &i=head[u];i;i=edge[i].next){
			int t=edge[i].to;
			if(vis[i>>1]) continue;
			vis[i>>1]=true;
			sk.push(t);
			break;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	init();
	rep(i,1,m){
		int a,b;
		scanf("%d%d",&a,&b);
		deg[a]++,deg[b]++;
		add(a,b);
		add(b,a);
	}
	int sum=0,st=1;
	rep(i,0,n-1){
		if(deg[i]%2){
			sum++; 
			st=i;
		}
	}
	if(sum==0||sum==2){
		puts("Yes");
		print(st);
		rep(i,1,ans[0])
			printf("%d\n",ans[i]);
	}
	else
		puts("No");
	return 0;
}
