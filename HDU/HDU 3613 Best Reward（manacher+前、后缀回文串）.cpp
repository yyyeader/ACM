#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e6+5;
const int INF=0x3f3f3f3f;

int len1,len2;
int p[N],sum[N],val[N],pre[N],hou[N];
char s[N],str[N];

void init(){
    str[0]='$';
    str[1]='#';
    for(int i=0;i<len1;i++){
        str[i*2+2]=s[i];
        str[i*2+3]='#';
    }
    len2=len1*2+2;
    str[len2]='\0';
}

void manacher(){
    int id=0,mx=0;
    for(int i=1;i<len2;i++){
        if(mx>i) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        while(str[i+p[i]]==str[i-p[i]])
            p[i]++;
        if(p[i]+i>mx){
            id=i;
            mx=p[i]+i;
        }
        if(i-p[i]==0){
            pre[p[i]+i-1]=1;
        }
        if(i+p[i]==len2){
            hou[i-p[i]+1]=1;
        }
    }
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(pre,0,sizeof(pre));
        memset(hou,0,sizeof(hou));
        for(int i=0;i<26;i++){
            scanf("%d",&val[i]);
        }
        scanf("%s",s);
        len1=strlen(s);
        init();
        manacher();
        for(int i=1;i<len2;i++){
            if(i=='#') sum[i]=sum[i-1];
            else sum[i]=sum[i-1]+val[str[i]-'a'];
        }
        int ans=-INF;
        //Ã¶¾Ù·Ö¸îµã
        for(int i=2;i<len2-1;i++){
            int tmp=0;
            if(pre[i]) tmp+=sum[i];
            if(hou[i]) tmp+=sum[len2-1]-sum[i];
            ans=max(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
