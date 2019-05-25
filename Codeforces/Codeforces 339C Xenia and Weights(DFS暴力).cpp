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
const int N=5e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

vector<int>pan;
string str;
int m;
int ans[N];
bool flag;

//w是剩余重量,tmp是上一次使用的重量,step是当前步数 
void dfs(int w,int pre,int step){
	if(flag) return;
	if(step>m){
		flag=true;
		cout<<"YES"<<endl;
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<(i==m?'\n':' ');
		}
		return;
	}
	for(int i=0;i<pan.size();i++){
		int t=pan[i];
		if(t!=pre&&t>w){
			ans[step]=t;
			dfs(t-w,t,step+1);
		}
	}
}

int main(){
	FAST_IO;
	cin>>str>>m;
	for(int i=0;i<str.size();i++){
		if(str[i]=='1')
			pan.push_back(i+1);
	}
	dfs(0,-1,1); 
	if(!flag)
		cout<<"NO"<<endl;
	return 0;
}

