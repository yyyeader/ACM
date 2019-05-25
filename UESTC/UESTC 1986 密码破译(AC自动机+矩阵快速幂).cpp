#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define LL long long
using namespace std;
const int N=1e2+5;
const LL MOD=1e9+7;

struct Matrix{
    LL m[N][N];
    Matrix(){
        memset(m,0,sizeof(m));
    }
}mt1,mt2;
int idx;
int trie[N][4],fail[N];
bool flag[N];
char s[N];

int newnode(){
	for(int i=0;i<4;i++){
		trie[idx][i]=-1;
	}
	flag[idx++]=false;
	return idx-1;
}

void init(){
	idx=0;
	newnode();
}

void insert(char *s){
	int len=strlen(s);
	int now=0;
	for(int i=0;i<len;i++){
		int ch=s[i]-'0';
		if(trie[now][ch]==-1)
			trie[now][ch]=newnode();
		now=trie[now][ch];
	}
	flag[now]=true;
}

void getfail(){
	queue<int>q;
	for(int i=0;i<4;i++){
		if(trie[0][i]!=-1){
			fail[trie[0][i]]=0;
			q.push(trie[0][i]);
		}
		else trie[0][i]=0;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		if(flag[fail[u]])
			flag[u]=true;
		for(int i=0;i<4;i++){
			if(trie[u][i]!=-1){
				fail[trie[u][i]]=trie[fail[u]][i];
				q.push(trie[u][i]);
			}
			else trie[u][i]=trie[fail[u]][i];	
		}
	}
}

void get_matrix(){
	for(int i=0;i<idx;i++){
		if(flag[i]) continue;
		for(int j=0;j<4;j++){
            if(!flag[trie[i][j]])
                mt1.m[i][trie[i][j]]++;
    	}
	}
}


Matrix Mul(Matrix a,Matrix b){
    Matrix c;
    for(int i=0;i<idx;i++)
        for(int j=0;j<idx;j++)
            for(int k=0;k<idx;k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
    return c;
}

Matrix fastm(Matrix a,int n){
    Matrix res;
    for(int i=0;i<idx;i++) res.m[i][i]=1;
    while(n){
        if(n&1)
            res = Mul(res,a);
        a = Mul(a,a);
        n>>=1;
    }
    return res;
}

int main(){
	LL n,m;
	scanf("%lld%lld",&n,&m);
	init();
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		insert(s);
	}
	getfail();
	get_matrix();
	mt2=fastm(mt1,n); 
    LL ans=0;
    for(int i=0;i<=idx;i++){
        ans=(ans+mt2.m[0][i])%MOD;
    }
    printf("%lld\n",ans);
	return 0;
}
