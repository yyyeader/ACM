#include<bits/stdc++.h>
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
const int N=1e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int ans;
vector<int>v[N];

int dfs(int u,int fa){
	int sze=1;
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(t==fa) continue;
		sze+=dfs(t,u);
	}
	if(sze%2==0)
		ans++;
	return sze;
}

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(n%2)
		cout<<"-1"<<endl;
	else{
		dfs(1,-1);
		cout<<ans-1<<endl;
	} 
	return 0;
}

