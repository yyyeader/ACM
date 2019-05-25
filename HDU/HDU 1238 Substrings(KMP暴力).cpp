#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=105;

int n;
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

bool check(char *p){
    for(int i=1;i<n;i++){
        if(!kmp(p,s[i]))
            return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int len=strlen(s[0]),idx=-1,ans=0;
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(j-i+1<=ans) continue;
                //顺序
                int cnt=0;
                char p[105];
                for(int k=i;k<=j;k++){
                    p[cnt++]=s[0][k];
                }
                p[cnt]='\0';
                if(check(p)){
                    ans=j-i+1;
                    idx=i;
                }
                //逆序
                cnt=0;
                for(int k=j;k>=i;k--){
                    p[cnt++]=s[0][k];
                }
                p[cnt]='\0';
                if(check(p)){
                    ans=j-i+1;
                    idx=i;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
