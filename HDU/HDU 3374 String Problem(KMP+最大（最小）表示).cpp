#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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

//求出最大/最小表示
int min_max_express(int flag){
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len){
        int t=p[(i+k)%len]-p[(j+k)%len];
        if(t==0) k++;
        else{
            if(flag){
                if(t<0) j+=k+1;
                else i+=k+1;
            }
            else{
                if(t>0) j+=k+1;
                else i+=k+1;
            }
            if(i==j) j++;
            k=0;
        }
    }
    return min(i,j)+1;       //数组下标从0开始，题目是从1开始
}

int main(){
    while(~scanf("%s",p)){
        len=strlen(p);
        int min_idx=min_max_express(1);
        int max_idx=min_max_express(0);
        getnext();
        int mmin=len-nxt[len];
        int res=len%mmin?1:len/mmin;
        printf("%d %d %d %d\n",min_idx,res,max_idx,res);
    }
    return 0;
}
