#include<iostream>
#include<cstdio>
#include<cstring>
#define CLR(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int N=15;

int k,cnt;
int ans[1<<N];
bool vis[1<<N];

void init(){
	CLR(vis,false);
	CLR(ans,0);
	cnt=0;
}

void euler(int st) {
    int s1=(st<<1)&((1<<k)-1);
    int s2=s1+1;
    if (!vis[s1]){
        vis[s1]=1;
        euler(s1);
        ans[++cnt]=0;
    }
    if (!vis[s2]) {
        vis[s2]=1;
        euler(s2);
        ans[++cnt]=1;
    }
}

int main(){
	while(~scanf("%d",&k)){
		init();
		euler(0);
		printf("%d ",cnt);
		//因为要求字典序最小,所以前k位都是0
		for(int i=1;i<k;i++){
			printf("0");
		}
		for(int i=cnt;i>=k;i--){
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
