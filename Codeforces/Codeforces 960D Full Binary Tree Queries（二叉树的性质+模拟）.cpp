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

LL f[N],p[N],sum[N];

int main(){
    FAST_IO;
    LL tmp=1;
    for(int i=0;i<=62;i++){
        f[i]=1LL<<i;
    }
    int q;
    cin>>q;
    while(q--){
        LL op,x,k;
        cin>>op;
        if(op==1){
            cin>>x>>k;
            LL pos=0;
            for(int i=1;i<=62;i++){
                if(f[i]-1>=x){
                   pos=i-1;
                   break;
                }
            }
            p[pos]=(p[pos]+k+f[pos])%f[pos];
        }
        if(op==2){
            cin>>x>>k;
            LL pos=0;
            for(int i=1;i<=62;i++){
                if(f[i]-1>=x){
                   pos=i-1;
                   break;
                }
            }
            LL tmp=(k%f[pos]+f[pos])%f[pos],lim=1e18;
            while(f[pos]-1<=lim){
                p[pos]=(p[pos]+tmp+f[pos])%f[pos];
                tmp*=2;
                pos++;
                tmp%=f[pos];
            }
        }
        if(op==3){
            cin>>x;
            if(x==1){
                cout<<x<<endl;
                continue;
            }
            LL pos=0;
            for(int i=1;i<=62;i++){
                if(f[i]-1>=x){
                   pos=i-1;
                   break;
                }
            }
            vector<LL>ans;
            ans.push_back(x);
            LL np=(x-f[pos]+p[pos]+f[pos])%f[pos];
            x=np+f[pos];
            while(pos!=0){
                pos--;
                x=x/2;
                ans.push_back(f[pos]+(x-f[pos]-p[pos]+f[pos])%f[pos]);
            }
            for(int i=0;i<ans.size();i++){
                if(i!=ans.size()-1)
                    cout<<ans[i]<<" ";
                else
                    cout<<ans[i]<<endl;
            }
        }
    }
	return 0;
}
