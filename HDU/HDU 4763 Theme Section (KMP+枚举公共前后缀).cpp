#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e6+5;

int nxt1[maxn],nxt2[maxn],p[maxn];
char s[maxn],str[maxn];

void getnext(char *t,int len,int *nxt){
    int i,j;
    i=0,j=nxt[0]=-1;
    while(i<len){
        while(j!=-1&&t[i]!=t[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

bool kmp(char *s,int len1,char *t,int len2){
    int i,j;
    i=j=0;
    getnext(t,len2,nxt2);
    while(i<len1){
        while(j!=-1&&s[i]!=t[j])
            j=nxt2[j];
        i++,j++;
        if(j==len2)
            return true;
    }
    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        getnext(s,len,nxt1);
        int t=nxt1[len];
        int ans=0;
        while(t>0){
            if(kmp(s+t,len-2*t,s,t)){
                ans=t;
                break;
            }
            t=nxt1[t];
        }
        printf("%d\n",ans);
    }
    return 0;
}
