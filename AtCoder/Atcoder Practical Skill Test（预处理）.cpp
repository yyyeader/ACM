#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const int N=1e3+5;

struct node{
    int x,y;
}pos[N*N];

int d;
int a[N][N],sum[90005][305];

void cal(int st,int en){
    int x=st,px=pos[x].x,py=pos[x].y;
    while(x!=en){
        if(en-x<d)
            break;
        x+=d;
        sum[x][st]=abs(pos[x].x-px)+abs(pos[x].y-py);
        if(x>d)
            sum[x][st]+=sum[x-d][st];
        px=pos[x].x;
        py=pos[x].y;
    }
}

int cal2(int st,int en){
    int x=st,px=pos[x].x,py=pos[x].y,ans=0;
    while(x!=en){
        x+=d;
        ans+=abs(pos[x].x-px)+abs(pos[x].y-py);
        px=pos[x].x;
        py=pos[x].y;
    }
    return ans;
}


int main(){
    int h,w;
    scanf("%d%d%d",&h,&w,&d);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf("%d",&a[i][j]);
            pos[a[i][j]].x=i;
            pos[a[i][j]].y=j;
        }
    }
    int q;
    scanf("%d",&q);
    if(d<=300){
        for(int i=0;i<=d-1;i++){
            cal(i,90000);
        }
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",sum[r][l%d]-sum[l][l%d]);
        }
    }
    else{
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",cal2(l,r));
        }
    }
    return 0;
}
