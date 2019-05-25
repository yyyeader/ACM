#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;

int len;
int nxt[N],ans[N];
char p[N];

void getnext(){
    int i=0,j=nxt[0]=-1;
    while(i<len){
        while(j!=-1&&p[i]!=p[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s",p);
        len=strlen(p);
        getnext();
        int t=nxt[len];
        int cnt=0;
        while(t!=-1){
            if(t>=0) ans[cnt++]=len-t;
            t=nxt[t];
        }
        printf("Case #%d: %d\n",++cas,cnt);
        for(int i=0;i<cnt;i++){
            printf("%d%c",ans[i],i==cnt-1?'\n':' ');
        }
    }
    return 0;
}
