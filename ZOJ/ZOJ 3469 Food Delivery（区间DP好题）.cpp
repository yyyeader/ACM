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
const int N=1e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

struct node{
    int x,b;
}p[N];
int sum[N];
int dp[N][N][2];          //用dp[i][j][0]表示访问完区间[i,j]并留在左端点，dp[i][j][1]表示访问完区间[i,j]并留在右端点。

bool cmp(node a,node b){
    return a.x<b.x;
}

int main(){
    FAST_IO;
    int n,v,st;
    while(cin>>n>>v>>st){
        for(int i=1;i<=n;i++){
            cin>>p[i].x>>p[i].b;
        }
        p[++n].x=st;
        p[n].b=0;
        sort(p+1,p+1+n,cmp);
        int pos;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+p[i].b;
            if(p[i].x==st)
                pos=i;
        }
        memset(dp,0x3f,sizeof(dp));
        dp[pos][pos][0]=dp[pos][pos][1]=0;
        for(int i=pos;i>=1;i--){
            for(int j=pos;j<=n;j++){
                if(i==j) continue;
                //如果从i+1这个点移动到i花费了时间t，那么除了i等待了t.
                //其它所有还没收到午餐的用户也都等待了t，因此要把他们的不满意度都算上
                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(sum[i]+sum[n]-sum[j])*(p[i+1].x-p[i].x));
                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(sum[i]+sum[n]-sum[j])*(p[j].x-p[i].x));

                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(sum[i-1]+sum[n]-sum[j-1])*(p[j].x-p[i].x));
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(sum[i-1]+sum[n]-sum[j-1])*(p[j].x-p[j-1].x));
            }
        }
        printf("%d\n",v*min(dp[1][n][0],dp[1][n][1]));
    }
	return 0;
}
