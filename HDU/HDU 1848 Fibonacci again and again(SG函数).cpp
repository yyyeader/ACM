#include<cstdio>
#include<cstring>
const int N=1e3+5;
int f[100]={0,1,2},sg[N];
bool vis[N];

void fib(){
	for(int i=3;i<=20;i++){
		f[i]=f[i-1]+f[i-2];
	}
}

void sg_get(void){
	memset(sg,0,sizeof(sg));
	for(int i=1;i<N;i++){
		memset(vis,false,sizeof(vis));
		for(int j=1;f[j]<=i;j++){
			vis[sg[i-f[j]]]=true;						
		}
		for(int j=0;j<N;j++){
			if(!vis[j]){
				sg[i]=j;
				break;
			}
		}
	}
}

int main(){
	fib();
	sg_get();
	int m,n,p;
	while(~scanf("%d%d%d",&m,&n,&p)&&(m||n||p)){
		int sum=0;
		sum=sg[m]^sg[n]^sg[p];
		if(sum)
			puts("Fibo");
		else
			puts("Nacci");
	}
} 
