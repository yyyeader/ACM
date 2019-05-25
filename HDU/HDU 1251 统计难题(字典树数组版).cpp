#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e5+5;

int idx,root=0;
int cnt[N],trie[N][26],val[N];

void init(){
    idx=1;
    memset(trie,-1,sizeof(trie));
    memset(val,0,sizeof(val));
}

void insert(char *s){
    int len=strlen(s);
    int now=root;
    for(int i=0;i<len;i++){
        int ch=s[i]-'a';
        if(trie[now][ch]==-1)
            trie[now][ch]=idx++;
        now=trie[now][ch];
        val[now]++;
    }
}

int query(char *s){
    int len=strlen(s);
    int now=root;
    for(int i=0;i<len;i++){
        int ch=s[i]-'a';
        if(trie[now][ch]==-1)
            return 0;
        now=trie[now][ch];
    }
    return val[now];
}

int main(){
    char str[15];
    init();
    while(gets(str)&&strcmp(str,"")){
        insert(str);
    }
    while(gets(str)){
        printf("%d\n",query(str));
    }
    return 0;
}
