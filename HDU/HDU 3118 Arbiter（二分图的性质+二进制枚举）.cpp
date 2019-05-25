#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e2+5;
const int INF=0x3f3f3f3f;

int n,m;
int mp[N][N];

int cal(int k){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //两个位置相等同为0或1,说明这两个位置处于同一个集合
            //为了使其成为二分图，所以删掉两点间的所有边（有重边）
            if((1&(k>>i))==(1&(k>>j))) ans+=mp[i][j];
        }
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(mp,0,sizeof(mp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            mp[a][b]++;mp[b][a]++;
        }
        int ans=INF;
        //注意特判
        if(n==0||m==0) ans=0;
        //暴力枚举n个数的状态（为0或者为1)
        for(int i=1;i<(1<<n);i++){
            ans=min(ans,cal(i));
        }
        printf("%d\n",ans);
    }
    return 0;
}
