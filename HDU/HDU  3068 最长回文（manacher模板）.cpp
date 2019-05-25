#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e6+5;

int len1,len2;
int p[N];
char s[N],str[N];

void init(){
    str[0]='$';
    str[1]='#';
    for(int i=0;i<len1;i++){
        str[i*2+2]=s[i];
        str[i*2+3]='#';
    }
    len2=len1*2+2;
    str[len2]='%';
}

void manacher(){
    int id=0,mx=0;
    for(int i=1;i<len2;i++){
        if(mx>i) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        while(str[i+p[i]]==str[i-p[i]])
            p[i]++;
        if(p[i]+i>mx){
            mx=p[i]+i;
            id=i;
        }
    }
}

int main(){
    while(~scanf("%s",s)){
        len1=strlen(s);
        init();
        manacher();
        int ans=0;
        for(int i=0;i<len2;i++){
            ans=max(ans,p[i]);
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
