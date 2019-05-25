#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
const int M=6e4+5;
const int N=1e4+5;

struct node{
    int next[128];
    int cnt,fail,id;
}trie[M];

int idx;
char s[N];
set<int>st;

void init(){
    for(int i=0;i<M;i++){
        memset(trie[i].next,0,sizeof(trie[i].next));
        trie[i].fail=trie[i].cnt=trie[i].id=0;
    }
    idx=0;
}

void Insert(char *s,int id){
    int n=strlen(s),now=0;
    for(int i=0;i<n;i++){
        char ch=s[i];
        if(!trie[now].next[ch])
            trie[now].next[ch]=++idx;
        now=trie[now].next[ch];
    }
    trie[now].cnt++;
    trie[now].id=id;
}

void getfail(){
    trie[0].fail=-1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<128;i++){
            if(trie[u].next[i]){
                if(u==0) trie[trie[u].next[i]].fail=0;
                else{
                    int tmp=trie[u].fail;
                    while(tmp!=-1){
                        if(trie[tmp].next[i]){
                            trie[trie[u].next[i]].fail=trie[tmp].next[i];
                            break;
                        }
                        tmp=trie[tmp].fail;
                    }
                    if(tmp==-1) trie[trie[u].next[i]].fail=0;
                }
                q.push(trie[u].next[i]);
            }
        }
    }
}

bool get(int u){
	bool flag=false;
    while(u){
        if(trie[u].cnt){
        	flag=true;
            st.insert(trie[u].id);
    	}
        u=trie[u].fail;
    }
    return flag;
}

bool match(char *s){
    int n=strlen(s),now=0,res=0,flag=false;
    for(int i=0;i<n;i++){
        char ch=s[i];
        if(trie[now].next[ch])
            now=trie[now].next[ch];
        else{
            int p=trie[now].fail;
            while(p!=-1&&trie[p].next[ch]==0)
                p=trie[p].fail;
            if(p==-1) now=0;
            else now=trie[p].next[ch];
        }
        if(get(now))
        	flag=true;
    }
    return flag;
}

int main(){
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        Insert(s,i);
    }
    getfail();

    int m,tot=0;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%s",s);
        st.clear();
        if(match(s)){
            tot++;
            printf("web %d:",i);
            for(auto it=st.begin();it!=st.end();it++){
                printf(" %d",*it);
            }
            printf("\n");
        }
    }
    printf("total: %d\n",tot);
    return 0;
}
