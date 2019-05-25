/*奇数层只要有一个true即返回true，偶数层只要有一个false就返回false
因为奇数层肯定是先手在选，偶数层是后手在选择。
链接：https://www.nowcoder.com/acm/contest/86/F 
*/
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
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=5e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int mmax[N],deep[N];
bool vis[N];
vector<int>v[N];

void dfs(int u){
	vis[u]=true;
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		deep[t]=deep[u]+1;
		if(!vis[t])
			dfs(t);
	}
}

bool solve(int u){
	vis[u]=true;
	int cnt=0,num=0;
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(!vis[t]){
			cnt++;
			if(!solve(t))
				num++;
		}
	}
	if(cnt==0){
		if(deep[u]%2)
			return false;
		return true;
	}
	else{
		if(deep[u]%2==0){
			if(num==0)
				return true;
			return false;
		}
		else{
			if(num<cnt)
				return true;
			return false;
		}
	}
}

int main(){
	FAST_IO;
	int t;
	cin>>t;
	while(t--){
		memset(vis,false,sizeof(vis));
		int n,r;
		cin>>n>>r;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n-1;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		deep[r]=1;
		dfs(r);
		memset(vis,false,sizeof(vis));
		if(!solve(r))
			cout<<"Dui"<<endl;
		else
			cout<<"Gen"<<endl;
	}
	return 0;
}
