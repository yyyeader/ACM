#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e6+5;
const int MOD=10007;

int m;
int nxt[N],cnt[N];
char p[N];

void getnext(){
    int i,j;
    i=0,j=nxt[0]=-1;
    while(i<m){
        while(j!=-1&&p[i]!=p[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&m,p);
        getnext();
        cnt[0]=0;
        int sum=0;
        //cnt[i]=cnt[next[i]]+1;
        for(int i=1;i<=m;i++){
            cnt[i]=cnt[nxt[i]]+1;
            sum=(sum+cnt[i])%MOD;
        }
        printf("%d\n",sum);
    }
    return 0;
}
