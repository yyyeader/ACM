#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e6+5;
const int M=5e5+5;

int idx;
int trie[M][26],fail[M],cnt[M];
char s[N];

int newnode(){
    for(int i = 0 ; i < 26 ; i++) {
        trie[idx][i] = -1;
    }
    cnt[idx++] = 0;
    return idx - 1;
}

void init(){
    idx=0;
    newnode();
}

//����ģʽ��
void Insert(char *s){
    int len=strlen(s);
    int now=0;
    for(int i=0;i<len;i++){
        int ch=s[i]-'a';
        if(trie[now][ch]==-1)
            trie[now][ch]=newnode();
        now=trie[now][ch];
    }
    cnt[now]++;
}

//���failָ��
void getfail(){
    fail[0]=0;
    queue<int>q;
    for(int i=0;i<26;i++){
        if(trie[0][i]==-1)
            trie[0][i]=0;
        else{
            fail[trie[0][i]]=0;
            q.push(trie[0][i]);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(trie[u][i]!=-1){
                fail[trie[u][i]]=trie[fail[u]][i];
                q.push(trie[u][i]);
            }
            else trie[u][i]=trie[fail[u]][i];
        }
    }
}

//�������˼�����a������s�У���ô��Ϊa��׺��b�϶�Ҳ��s�У����Բ����Һ�׺
int get(int u){
    int res=0;
    while(u){
        res+=cnt[u];
        cnt[u]=0;
        u=fail[u];
    }
    return res;
}

//�ַ���ƥ��
int match(char *s){
    int len=strlen(s),now=0,ans=0;
    for(int i=0;i<len;i++){
        int ch=s[i]-'a';
        now=trie[now][ch];
        //if(cnt[now])         //ע�����ﲻ���ж�cnt[now]>0,������she����ģʽ��she��h����h��sh�ĵĺ�׺��cnt[�ڵ�h]=0��
        ans+=get(now);
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            Insert(s);
        }
        scanf("%s",s);
        getfail();
        printf("%d\n",match(s));
    }
    return 0;
}
