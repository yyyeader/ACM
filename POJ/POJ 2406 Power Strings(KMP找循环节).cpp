#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e6+5;

int m;
int nxt[N];
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
    while(~scanf("%s",p)&&strcmp(p,".")){
        m=strlen(p);
        getnext();
        int mmin=m-nxt[m];
        if(m%mmin==0)
            printf("%d\n",m/mmin);
        else
            puts("1");
    }
    return 0;
}
