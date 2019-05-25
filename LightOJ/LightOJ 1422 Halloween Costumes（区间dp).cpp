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
const int N=5e2+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int a[N];
int dp[N][N];

int main(){
    int t,n,cas=0;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            dp[i][i]=1;        //һ��ʼdp[i][i] = 1�������ʼ�ĵ�i���ɶ���Ҫ��1���·���
        }
        for(int len=1;len<n;len++){
            for(int i=1;i+len<=n;i++){
                int j=i+len;
                dp[i][j]=dp[i][j-1]+1;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                //��� a[i] == a[j] �Ļ�����ô��������㴩�ü��·����յ�����ѵ�֮ǰ���·���֮ǰ���·������Դ���Ҫ-1��
                if(a[i]==a[j])
                    dp[i][j]--;
            }
        }
        printf("Case %d: %d\n",++cas,dp[1][n]);
    }
	return 0;
}
