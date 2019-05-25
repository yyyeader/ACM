#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+5;

struct node{
	int next[2];
	int val;
	void reset(){
		next[0]=next[1]=val=0;
	}
}T[N*32];//�����СΪ���ָ���*���λ�� 

int cnt;//�ֵ����ϵĽڵ����

void init(){
	cnt=0;
	T[0].reset();
} 

//��x���뵽01�ֵ����� 
void insert(int x){
	int cur=0;//�Ӹ��ڵ㿪ʼ
	for(int i=31;i>=0;i--){
		int t=(x>>i)&1;
		if(!T[cur].next[t]){
			//����һ���½ڵ��ʼ��
			T[++cnt].reset();
			T[cur].next[t]=cnt;
		}
		cur=T[cur].next[t];
	}
	//����x 
	T[cur].val=x;
}

//��ѯ���ֵ����в��Һ�x����ֵ����Ԫ�� 
int query(int x){
	int cur=0;
	for(int i=31;i>=0;i--){
		int t=(x>>i)&1;
		//̰��,�����Ҳ�ͬ��ʹ���ֵ��� 
		if(T[cur].next[t^1])
			cur=T[cur].next[t^1];
		else
			cur=T[cur].next[t];
	}
	return T[cur].val;
}

int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		init();
		int n,m,x;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			insert(x);
		}
		printf("Case #%d:\n",++cas);
		for(int i=1;i<=m;i++){
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}
