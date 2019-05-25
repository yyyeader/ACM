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
const int N=1e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next;
}edge[M];

int cnt,n;
int head[N],deg[N];
bool flag[N];
char mp[N][N];

void add(int u,int v){
	edge[cnt]=node{v,head[u]};
	head[u]=cnt++;
}

void init(){
	cnt=2;
	memset(deg,0,sizeof(deg));
	memset(flag,false,sizeof(flag));
	memset(head,0,sizeof(head));
}

void topo(){
	priority_queue<int,vector<int>,greater<int> >q;
	vector<int>ans;
	for(int i=1;i<=2*n;i++){
		if(deg[i]==0){
			q.push(i);
			flag[i]=true;
		}
	}
	while(!q.empty()){
		int u=q.top();
		q.pop();
		ans.push_back(u);
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			deg[t.to]--;
			if(deg[t.to]==0)
				q.push(t.to);
		}
	}
	if(ans.size()!=2*n){
		puts("No solution");
		return;
	}
	for(int i=0;i<ans.size();i++){
		int t=ans[i];
		if(flag[t]) continue;
		if(t>n)
			printf("R%d",t-n);
		else
			printf("C%d",t);
		if(i!=ans.size()-1)
			printf(" ");
		else
			printf("\n");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=n;j++){
				if(mp[i][j]=='O'){
					add(i+n,j);
					deg[j]++;
				}
				else{
					add(j,i+n);
					deg[i+n]++;
				}
			}
		}
		topo();
	}
	return 0;
}

