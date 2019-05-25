#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
const int N=1e6+5;

int m;
int nxt[N],ans[N];
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
    while(~scanf("%s",p)){
        m=strlen(p);
        getnext();
        int cnt=0;
        ans[cnt++]=m;
        int t=m;
        while(t!=-1){
            if(nxt[t]>0)
                ans[cnt++]=nxt[t];
            t=nxt[t];
        }
        for(int i=cnt-1;i>=0;i--){
            printf("%d%c",ans[i],i==0?'\n':' ');
        }
    }
    return 0;
}
