#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=50000;
const int M=100000;

int mid;
int n,m,need,ans,cnt,tmp;

struct node{
    int from,to,w,col;
}edge[M+5];

int root[N+5];

int find(int x) {
	return root[x]==-1?x:root[x]=find(root[x]);
}

bool cmp(node a,node b) {
	return a.w+(a.col^1)*mid==b.w+(b.col^1)*mid?a.col<b.col:a.w+(a.col^1)*mid<b.w+(b.col^1)*mid;
}

int check(){
    tmp=cnt=0;
    int k=0;
    memset(root,-1,sizeof(root));
    sort(edge+1,edge+1+m,cmp);
    for (int i=1;i<=m;i++){
        int t1=find(edge[i].from);
        int t2=find(edge[i].to);
        if (t1!=t2){
            k+=edge[i].col^1;
            root[t1]=t2;
            cnt++;
            tmp+=edge[i].w;
            if (cnt==n-1) break;
        }
    }
    return k;
}

int main(){
    scanf("%d%d%d",&n,&m,&need);
    for (int i=1;i<=m;i++){
    	int from,to,w,col;
		scanf("%d%d%d%d",&from,&to,&w,&col);
		edge[i]=node{from,to,w,col};
	}
    int l=-100,r=100;
    while (l<=r){
        mid=(l+r)>>1;
        if (check()>=need){
        	l=mid+1,ans=tmp;
		}
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
