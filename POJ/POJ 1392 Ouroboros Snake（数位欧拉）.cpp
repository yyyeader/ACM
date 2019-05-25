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
    //���������0,�ٳ������1 
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
		cnt+=n-1;			//cnt��ʱ����2^n��Ҫ���Ͽ�ͷ0��n-1λ
		cnt-=k;				//��λ����k���� 
		int t=0;
		for(int i=0;i<n;i++){
			t=t*2+ans[cnt-i];
		}
		printf("%d\n",t);
	}
	return 0;
}
