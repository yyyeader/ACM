#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1e5+5;

LL t[N],sum[N],v[N];                             //sum[i]是t[i]的前缀和

int main(){
    priority_queue<LL,vector<LL>,greater<LL> >q;
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);

    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&t[i]);
        sum[i]=t[i]+sum[i-1];
    }
    for(int i=1;i<=n;i++){
        q.push(v[i]+sum[i-1]);                  //加上sum[i-1]，可以在减的时候将前一段没有消融的sum[i-1]抵消掉
        LL ans=t[i]*q.size();                   //先假设没有一堆雪不够消融t[i]
        while(!q.empty()&&q.top()<=sum[i]){     //找到不够t[i]的，减掉差值（不够的部分）
            ans+=q.top()-sum[i];
            q.pop();
        }
        printf("%lld%c",ans,i==n?'\n':' ');
    }
    return 0;
}
