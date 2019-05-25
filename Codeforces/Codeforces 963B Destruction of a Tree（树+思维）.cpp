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
const int N=2e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int siz[N];
vector<int>v[N];

void dfs(int u){
    siz[u]=1;
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        dfs(t);
        siz[u]+=siz[t];
    }
}

void solve(int u){
    //先删掉最底下的偶数点
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(siz[t]%2==0)
            solve(t);
    }
    printf("%d\n",u);
    //删掉了根节点之后,原来的奇数点变成了偶数点,可以删除
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(siz[t]%2)
            solve(t);
    }
}

int main(){
    int n,rt;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==0)
            rt=i;
        else
            v[x].push_back(i);
    }
    if(n%2!=0){
        puts("YES");
        dfs(rt);
        solve(rt);
    }
    else
        puts("NO");
	return 0;
}
