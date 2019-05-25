#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;

int nxt[N];
char s1[N],s2[N];

void getnext(char *p,int m){
    int i,j;
    i=0,j=nxt[0]=-1;
    while(i<m){
        while(j!=-1&&p[i]!=p[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

int main(){
    while(~scanf("%s",s1)){
        scanf("%s",s2);
        int m=strlen(s1),n=strlen(s2);
        int cnt=m;
        //合并s1,s2求nxt数组
        for(int i=0;i<n;i++){
            s1[cnt++]=s2[i];
        }
        s1[cnt]='\0';
        getnext(s1,cnt);
        int ans=nxt[cnt];
        //s1、s2合并后公共前后缀长度可能大于s1或s2原来的长度，所以要回溯一下找到长度刚好小于s1、s2的公共前后缀
        while(ans!=-1){
            if(ans<=m&&ans<=n)
                break;
            ans=nxt[ans];
        }
        if(ans>0){
            for(int i=0;i<ans;i++){
                printf("%c",s1[i]);
            }
            printf(" %d\n",ans);
        }
        else
            printf("%d\n",ans);
    }
    return 0;
}
