#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;

int len;
int nxt[N];
char p[N];

void getnext(){
    int i,j;
    i=0,j=nxt[0]=-1;
    while(i<len){
        while(j!=-1&&p[i]!=p[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",p);
        len=strlen(p);
        getnext();
        int mmin=len-nxt[len];              //len-nxt[len]Ϊ�ַ�������Сѭ����
        if(len!=mmin&&len%mmin==0)          //������������ѭ����
            puts("0");
        else
            printf("%d\n",mmin-len%mmin);   //len%mmin��ͬ��"abcab"����"abc"
    }
    return 0;
}
