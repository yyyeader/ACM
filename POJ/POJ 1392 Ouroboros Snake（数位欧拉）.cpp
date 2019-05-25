#include<iostream>
#include<cstdio>
#include<cstring>
#define CLR(arr,val)  memset(arr,val,sizeof(arr))
using namespace std;
const int N=16;

int n,k,cnt;
int ans[1<<N];
bool vis[1<<N];

void euler(int st) {
    int s1=(st<<1)&((1<<n)-1);
    int s2=s1+1;
    //先试着添加0,再尝试添加1 
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

void init(){
	CLR(vis,false);
	CLR(ans,0);
	cnt=0;
}

int main(){
	while(~scanf("%d%d",&n,&k)&&(n||k)){
		init();
		euler(0);	
		cnt+=n-1;			//cnt此时等于2^n还要补上开头0的n-1位
		cnt-=k;				//定位到第k个数 
		int t=0;
		for(int i=0;i<n;i++){
			t=t*2+ans[cnt-i];
		}
		printf("%d\n",t);
	}
	return 0;
}
