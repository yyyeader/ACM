#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=105;

int nxt[N];
char s[N][N];

void getnext(char *p,int m){
    int i,j;
    i=0,j=nxt[0]=-1,m=strlen(p);
    while(i<m){
        while(j!=-1&&p[i]!=p[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

bool kmp(char *p,char *s){
    int m=strlen(p),n=strlen(s),i=0,j=0;
    getnext(p,m);
    while(i<n){
        while(j!=-1&&s[i]!=p[j])
            j=nxt[j];
        i++,j++;
        if(j==m)
            return true;
    }
    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
        }
        char p[205],ans[205];
        int len=strlen(s[0]),mlen=0;
        for(int i=0;i<len;i++){
            for(int j=i+2;j<len;j++){
                if(j-i+1<mlen) continue;
                int cnt=0;
                for(int k=i;k<=j;k++){
                    p[cnt++]=s[0][k];
                }
                p[cnt]='\0';
                bool flag=true;
                for(int k=1;k<n;k++){
                    if(!kmp(p,s[k])){
                        flag=false;
                        break;
                    }
                }
                if(flag&&(mlen==0||mlen<j-i+1||mlen==j-i+1&&strcmp(p,ans)<0)){
                    mlen=j-i+1;
                    strcpy(ans,p);
                }
            }
        }
        if(mlen==0)
            puts("no significant commonalities");
        else
            printf("%s\n",ans);
    }
    return 0;
}
