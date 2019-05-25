#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cctype>
#include<algorithm>
using namespace std;
const int N=2e6+5;
const int M=1e5+5;

int idx;
int trie[M][26],id[M],cnt[M],fail[M],res[1005];
char s[1005][105],str[N];

void init(){
    memset(trie,0,sizeof(trie));
    memset(cnt,0,sizeof(cnt));
    memset(res,0,sizeof(res));
    memset(id,-1,sizeof(id));
    memset(fail,0,sizeof(fail));
    idx=0;
}

void Insert(char *s,int x){
    int len=strlen(s),now=0;
    for(int i=0;i<len;i++){
        int ch=s[i]-'A';
        if(!trie[now][ch])
            trie[now][ch]=++idx;
        now=trie[now][ch];
    }
    id[now]=x;
    cnt[now]++;
}

void getfail(){
    fail[0]=-1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(trie[u][i]){
                if(u==0) fail[trie[u][i]]=0;
                else{
                    int t=fail[u];
                    while(t!=-1&&trie[t][i]==0) t=fail[t];
                    if(t==-1) fail[trie[u][i]]=0;
                    else fail[trie[u][i]]=trie[t][i];
                }
                q.push(trie[u][i]);
            }
            else trie[u][i]=trie[fail[u]][i];
        }
    }
}

void get(int u){
    while(u){
        res[id[u]]+=cnt[u];
        u=fail[u];
    }
}

void match(char *s){
    int len=strlen(s),now=0;
    for(int i=0;i<len;i++){
        //注意判断一下，不是大写字母直接跳过
        if(!isupper(s[i])){
            now=0;
            continue;
        }
        int ch=s[i]-'A';
        if(trie[now][ch])
            now=trie[now][ch];
        else{
            int p=fail[now];
            while(p!=-1&&trie[p][ch]==0) p=fail[p];
            if(p==-1) now=0;
            else now=trie[p][ch];
        }
        if(cnt[now])
            get(now);
    }
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        init();
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
            Insert(s[i],i);
        }
        getfail();
        scanf("%s",str);
        match(str);
        for(int i=0;i<n;i++){
            if(res[i])
                printf("%s: %d\n",s[i],res[i]);
        }
    }
    return 0;
}
