#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long 
using namespace std;
const int M = 2e6+5;  
const LL MOD= 1e9+7;
const int N = 12;

char str[M];

LL cal(LL c,LL pre,LL id){
	LL now=c;
	if(id==1){
		return c;
	}
	LL t=pre;
	while(pre){
		now=now*10%MOD;
		pre/=10;
	}
	now=(now*10+t*10+c)%MOD;
	return now;
}

struct hw{
    int next[M][N];
    int fail[M];
    int num[M];
    int len[M];
    int S[M];
    LL sum[M],ans;
    int last;
    int n;
    int p;

    LL newnode ( LL l ) {
        for ( LL i = 0 ; i < N ; ++ i ) next[p][i] = 0 ;  
        num[p] = 0 ;  
        len[p] = l ;  
        return p ++ ;  
    }  

    void init () {
    	ans=0;
    	memset(sum,0,sizeof(sum));
        p = 0 ;  
        newnode (  0 ) ;  
        newnode ( -1 ) ;  
        last = 0 ;  
        n = 0 ;  
        S[n] = -1 ; 
        fail[0] = 1 ;  
    }  

    LL get_fail ( LL x ) {
        while ( S[n - len[x] - 1] != S[n] ) x = fail[x] ;  
        return x ;  
    }  

    void add(char ch){
        LL c=ch-'0'; 
        S[++n]=c;
        LL cur=get_fail(last);
        if (!next[cur][c]){
            LL now=newnode(len[cur] + 2);
            sum[now]=cal(c,sum[cur],cur);
            ans=(ans+sum[now])%MOD;
            fail[now]=next[get_fail(fail[cur])][c];
            next[cur][c]=now;
            num[now]=num[fail[now]]+1;
        }
        last = next[cur][c]; 
    }
}hws;

int main(){
	scanf("%s",str);
	LL len=strlen(str);
	hws.init();
	for(LL i=0;i<len;i++){
		hws.add(str[i]);
	}
	printf("%lld\n",hws.ans%MOD);
	return 0;
}
