#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;

int n,m;
char s[N],p[N];
int nxt[N];

void getnext(){
    int i,j;
    i=0,j=nxt[0]=-1;
    while(i<m){
        while(j!=-1&&p[i]!=p[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

int kmp(){
    getnext();
    int i=0,j=0,n=strlen(s),ans=0;
    while(i<n){
        while(j!=-1&&s[i]!=p[j])
            j=nxt[j];
        i++,j++;
        if(j==m){
            ans++;
            j=nxt[j];
        }
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",p,s);
        n=strlen(s),m=strlen(p);
        cout<<kmp()<<endl;
    }
    return 0;
}
