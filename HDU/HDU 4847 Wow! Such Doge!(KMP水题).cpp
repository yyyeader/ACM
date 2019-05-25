#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;

int len1,len2;
int nxt[N];
char s[N];

void getnext(char *t,int len){
    int i,j;
    i=0,j=nxt[0]=-1;
    while(i<len){
        while(j!=-1&&t[i]!=t[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

int kmp(char *s,char *t){
    int len1=strlen(s);
    int len2=strlen(t);
    getnext(t,len2);
    int i,j,cnt;
    i=j=cnt=0;
    while(i<len1){
        while(j!=-1&&tolower(s[i])!=t[j])
            j=nxt[j];
        i++,j++;
        if(j==len2){
            j=0;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int ans=0;
    while(gets(s)){
        int t=kmp(s,"doge");
        ans+=t;
    }
    printf("%d\n",ans);
    return 0;
}
//水题，第8行的‘O’我还以为是0呢，结果揣摩了半天的题意。。。。
