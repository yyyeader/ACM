#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e4+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

vector<int>v[N];
int a[N],b[N];
bool vis[N];

void dfs(int u){
	vis[u]=true;
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(vis[t]) continue;
		dfs(t);
	}
}

int main(){
	int n,s;
	while(~scanf("%d%d",&n,&s)){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	
		if(!a[1]||!a[s]&&!b[s]){
			puts("NO");
			continue;
		} 
		if(a[1]&&a[s]){
			puts("YES");
			continue;
		}
		bool flag=false;
		for(int i=s+1;i<=n;i++){
			if(a[i]&&b[i]){
				flag=true;
				break;
			}
		}
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
 
