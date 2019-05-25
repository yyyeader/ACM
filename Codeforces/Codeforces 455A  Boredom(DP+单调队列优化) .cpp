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
#define INF 0x3f3f3f3f
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FOR(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=5e6+5;

LL dp[N],cnt[N],q[N];

int main(){
    FAST_IO;
    vector<int>v;
    int n,lim=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        cnt[x]++;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    LL ans=0,head=0,tail=0,cur=0;
    q[tail++]=0;
    for(int i=0;i<v.size();i++){
        while(head<tail-1&&q[head]<=q[head+1]){
            head++;
        }
        dp[i]=q[head]+cnt[v[i]]*v[i];
        ans=max(dp[i],ans);
        while(cur<=i&&v[cur]<v[i+1]-1){
            LL t=dp[cur];
            while(head<tail&&q[tail-1]<=t){
                tail--;
            }
            q[tail++]=t;
            cur++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
