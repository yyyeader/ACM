#include<stdio.h>
#include<iostream>
using namespace std;
const int N=5e4+5;
int root[N],state[N];
int n;

/*int find(int x){
	int temp=x;
	while(x!=root[x]){
		state[x]=(state[x]+state[root[x]])%3;//更新每个动物的状态 
		x=root[x];
	}
	root[temp]=x;
	return x;
}*/
 
int find(int x){
	if(x==root[x])
		return x;
	int t=find(root[x]);
	state[x]=(state[x]+state[root[x]])%3;//更新每个动物的状态
	root[x]=t;
	return root[x];
}

void init(){
	int i;
	for(i=1;i<=n;i++){
		root[i]=i;
		state[i]=0;
	}
} 
int main(){
	int k,d,x,y,a,b,count=0;
	scanf("%d %d",&n,&k);
	init();//初始化 
	while(k--){
		scanf("%d %d %d",&d,&x,&y);
		if(x>n||y>n||d==2&&x==y){
			count++;
			continue;
		}
		a=find(x);
		b=find(y);
		if(d==1){
			if(a==b){
				if(state[x]!=state[y])//问题：为什么是x,y 
					count++;
			}
			else{
				root[a]=b;
				state[a]=state[y]-state[x];//state[a]+state[x]=state[y]
				state[a]=(state[a]+3)%3;//可能出现负数 
			}
		}
		else if(d==2){
			if(a==b){
				if((state[x]+1)%3!=state[y]){//记得要%3，比如x的权值是2,y的权值是0的时候 
				//问题：为什么是x,y不是a,b 
					count++;
				}
			}
			else{
				root[a]=b;
				state[a]=state[y]-state[x]-1;//steat[a]+state[x]+1=state[y],x吃y所以x的权值比y大1 
				state[a]=(state[a]+3)%3;//可能出现负数 
			}
		}
	//	printf("count=%d\n",count);
	}
	printf("%d\n",count); 
} 
