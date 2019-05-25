#include<stdio.h>
#include<iostream>
using namespace std;
const int N=5e4+5;
int root[N],state[N];
int n;

/*int find(int x){
	int temp=x;
	while(x!=root[x]){
		state[x]=(state[x]+state[root[x]])%3;//����ÿ�������״̬ 
		x=root[x];
	}
	root[temp]=x;
	return x;
}*/
 
int find(int x){
	if(x==root[x])
		return x;
	int t=find(root[x]);
	state[x]=(state[x]+state[root[x]])%3;//����ÿ�������״̬
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
	init();//��ʼ�� 
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
				if(state[x]!=state[y])//���⣺Ϊʲô��x,y 
					count++;
			}
			else{
				root[a]=b;
				state[a]=state[y]-state[x];//state[a]+state[x]=state[y]
				state[a]=(state[a]+3)%3;//���ܳ��ָ��� 
			}
		}
		else if(d==2){
			if(a==b){
				if((state[x]+1)%3!=state[y]){//�ǵ�Ҫ%3������x��Ȩֵ��2,y��Ȩֵ��0��ʱ�� 
				//���⣺Ϊʲô��x,y����a,b 
					count++;
				}
			}
			else{
				root[a]=b;
				state[a]=state[y]-state[x]-1;//steat[a]+state[x]+1=state[y],x��y����x��Ȩֵ��y��1 
				state[a]=(state[a]+3)%3;//���ܳ��ָ��� 
			}
		}
	//	printf("count=%d\n",count);
	}
	printf("%d\n",count); 
} 
