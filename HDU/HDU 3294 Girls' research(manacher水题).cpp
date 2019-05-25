#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;

int len1,len2;
char s[N],str[N];
int p[N];

void init(){
    str[0]='$';
    str[1]='#';
    for(int i=1;i<=len1;i++){
        str[i*2]=s[i];
        str[i*2+1]='#';
    }
    len2=len1*2+2;
    str[len2]='@';
}

void manacher(){
    init();
    int id=-1,mx=-1;
    for(int i=1;i<len2;i++){
        if(mx>i) p[i]=min(p[id*2-i],mx-i);
        else p[i]=1;
        while(str[i+p[i]]==str[i-p[i]])
            p[i]++;
        if(i+p[i]>i){
            mx=i+p[i];
            id=i;
        }
    }
}

int main(){
    char ch;
    while(~scanf("%c",&ch)){
        scanf("%s",s+1);
        len1=strlen(s+1);
        for(int i=1;i<=len1;i++){
            s[i]='a'+(s[i]-'a'-(ch-'a')+26)%26;
        }
        manacher();
        int l,r,mmax=-1;
        for(int i=0;i<=len2;i++){
            if(p[i]-1>=2&&p[i]-1>mmax){
                mmax=p[i]-1;
                l=(i-p[i]+2)/2;
                r=(i+p[i]-2)/2;
            }
        }
        if(mmax==-1)
            puts("No solution!");
        else{
            printf("%d %d\n",l-1,r-1);
            for(int i=l;i<=r;i++){
                printf("%c",s[i]);
            }
            puts("");
        }
        getchar();
    }
    return 0;
}
