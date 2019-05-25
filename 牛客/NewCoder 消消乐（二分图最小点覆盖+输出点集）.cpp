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
const int INF=0x3f3f3f3f;

int n,m;
int link[N],have[N]; 
bool visx[N],visy[N];
vector<int>v[N],row,col;

bool dfs(int u){
	visx[u]=true;
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(visy[t]) continue;
		visy[t]=true;
		if(!link[t]||dfs(link[t])){
			link[t]=u;
			have[u]=t;
			return true;
		}
	}
	return false;
}

int match(){
	int res=0;
	memset(link,0,sizeof(link));
	for(int i=1;i<=n;i++){
		memset(visy,false,sizeof(visy));
		if(dfs(i)) res++;
	}
	return res;
}

/* 
分别将两侧的独立点集找到，从左侧的所有未匹配的点出发，
找可以到的所有的点，最后左侧所有未到的点和右侧所有可以到的点就是最小独立集了
*/
void find(){
	memset(visx,false,sizeof(visx));
	memset(visy,false,sizeof(visy));
	for(int i=1;i<=n;i++)
		if(!have[i]) dfs(i);
	for(int i=1;i<=n;i++)
		if(!visx[i]) row.push_back(i);
	for(int i=1;i<=m;i++)
		if(visy[i+n]) col.push_back(i);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char tmp[4005];
		scanf("%s",tmp+1);
		for(int j=1;j<=m;j++){
			if(tmp[j]=='*')
				v[i].push_back(j+n);
		}
	}
	int ans=match();
	printf("%d\n",ans);
	find();
	//注意输出格式！！！ 
    printf("%d", row.size());
    for(int i = 0; i < row.size(); i++) printf(" %d", row[i]);
    puts("");
    printf("%d", col.size());
    for(int i = 0; i < col.size(); i++) printf(" %d", col[i]);
    puts("");
	return 0;
}

