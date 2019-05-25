#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;

int nxt[N];
char s[30],pass[30],text[N];//s将明文转密文，pass将密文转明文

void getnext(char *p,int m){
    int i,j;
    i=0,j=nxt[0]=-1;
    while(i<m){
        while(j!=-1&&p[i]!=p[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",s,text);
        int len=strlen(text);
        int mid=(len+1)/2;
        for(int i=0;i<26;i++){
            pass[s[i]-'a']=i+'a';
        }
        for(int i=mid;i<len;i++){
            text[i]=s[text[i]-'a'];
        }
        getnext(text,len);
        int res=nxt[len];
        //明码长度res不能超过密码
        while(res!=-1){
            if(res<=len-res)
                break;
            res=nxt[res];
        }
        for(int i=mid;i<len;i++){
            text[i]=pass[text[i]-'a'];
        }
        printf("%s",text);
        for(int i=res;i<len-res;i++){
            printf("%c",pass[text[i]-'a']);
        }
        puts("");
    }
    return 0;
}
