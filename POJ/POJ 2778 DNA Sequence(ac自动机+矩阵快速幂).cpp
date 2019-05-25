#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int MOD=1e5;
const int INF=0x3f3f3f3f;
const int N=105;

struct Matrix{
	LL m[N][N];
	Matrix(){
        memset(m,0,sizeof(m));
    }
}mt1,mt2;

struct aho{
	const int static KD=4;
	
	int idx;
	int fail[N],trie[N][KD],dir[256];
	bool flag[N];

	int newnode(){
		for(int i=0;i<KD;i++)
			trie[idx][i]=-1;
		return idx++;
	}
	
	void init(){
		dir['A']=0,dir['T']=1,dir['C']=2,dir['G']=3;
		idx=0;
		newnode();
		memset(mt1.m,0,sizeof(mt1.m));
		memset(flag,false,sizeof(flag));
	}
	
	void insert(char *s){
		int now=0;
		for(int i=0;s[i]!='\0';i++){
			int ch=dir[s[i]];
			if(trie[now][ch]==-1)
				trie[now][ch]=newnode();
			now=trie[now][ch];
		}
		flag[now]=true;
	}
	
	void getfail(){
		queue<int>q;
		for(int i=0;i<KD;i++){
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
			if(flag[fail[u]])
				flag[u]=true;
			for(int i=0;i<KD;i++){
				//Õâ¾ä 
				if(trie[u][i]==-1)
					trie[u][i]=trie[fail[u]][i];
				else{
					fail[trie[u][i]]=trie[fail[u]][i];
					q.push(trie[u][i]);
				}
			}
		}
	}	
}ac; 

void get_matrix(){
    for(int i=0;i<ac.idx;i++){
        for(int j=0;j<4;j++){
            if(!ac.flag[ac.trie[i][j]]){
                mt1.m[i][ac.trie[i][j]]++;
            }
        }
    }
}

Matrix Mul(Matrix a,Matrix b){
    Matrix c;
    for(int i=0;i<ac.idx;i++)
        for(int j=0;j<ac.idx;j++)
            for(int k=0;k<ac.idx;k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
    return c;
}

Matrix fastm(Matrix a,int n){
    Matrix res;
    for(int i=0;i<ac.idx;i++) res.m[i][i]=1;
    while(n){
        if(n&1)
            res = Mul(res,a);
        a = Mul(a,a);
        n>>=1;
    }
    return res;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		ac.init();
		char t[105];
		for(int i=0;i<n;i++){
			scanf("%s",t);
			ac.insert(t);
		}
		ac.getfail();
		get_matrix();
		mt2=fastm(mt1,m);
		LL ans=0;
		for(int i=0;i<ac.idx;i++)
			ans+=mt2.m[0][i];
		printf("%lld\n",ans%MOD);
	}
	return 0;
}

