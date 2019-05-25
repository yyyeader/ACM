#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
    int cas=0;
    while(scanf("%d",&m)&&m){
        scanf("%s",p);
        getnext();
        printf("Test case #%d\n",++cas);
        //枚举长度为2~m的字符串前缀
        for(int i=2;i<=m;i++){
            int mmin=i-nxt[i];          //len-nxt[len]为最小循环节
            if(i!=mmin&&i%mmin==0)
                printf("%d %d\n",i,i/mmin);
        }
        printf("\n");
    }
    return 0;
}
