#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;
const int INF=0x3f3f3f3f;

int nxt[N],extend1[N],extend2[N],val[N],sum[N];
char s[N],rs[N];

void getnext(char *t){
    int a,p,len;
    len=strlen(t);
    nxt[0]=len;
    for(int i=1,j=-1;i<len;i++,j--){
        if(j<0||i+nxt[i-a]>=p){
            if(j<0)
                p=i,j=0;
            while(p<len&&t[p]==t[j])
                p++,j++;
            nxt[i]=j;
            a=i;
        }
        else
            nxt[i]=nxt[i-a];
    }
}

void ex_kmp(char *s,char *t,int *extend){
    int a,p,len1,len2;
    len1=strlen(s);
    len2=strlen(t);
    for(int i=0,j=-1;i<len1;i++,j--){
        if(j<0||i+nxt[i-a]>=p){
            if(j<0)
                p=i,j=0;
            while(p<len1&&j<len2&&s[p]==t[j])
                p++,j++;
            extend[i]=j;
            a=i;
        }
        else extend[i]=nxt[i-a];
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<26;i++){
            scanf("%d",&val[i]);
        }
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++){
            rs[len-i-1]=s[i];
        }
        getnext(rs);
        ex_kmp(s,rs,extend1);
        getnext(s);
        ex_kmp(rs,s,extend2);
        for(int i=0;i<len;i++){
            sum[i]=val[s[i]-'a'];
            if(i!=0)
                sum[i]+=sum[i-1];
        }
        int ans=-INF;
        //枚举分割位置(把s[i]归给前面的子串)
        for(int i=0;i<len-1;i++){
            int tmp=0;
            if(extend2[len-i]==i) tmp+=sum[i];
            i++;
            if(extend1[i]==len-i) tmp+=sum[len-1]-sum[i-1];
            ans=max(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
