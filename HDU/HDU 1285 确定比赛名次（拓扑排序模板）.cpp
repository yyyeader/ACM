#include<iostream> 
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=5e2+5;

int n,m;
int degree[N];
bool G[N][N];
queue<int>q;

void toposort(){
	for(int i=1;i<=n;i++){
		//Ѱ�ҳ���Ϊ0�ĵ�
		int j=1;
		while(degree[j]!=0) j++;
		degree[j]--;
		q.push(j);
		//�������ĵ����ȼ�1,��ɾ����ýڵ�����ı�
		for(int k=1;k<=n;k++){
			if(G[j][k])
				degree[k]--;
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(G,false,sizeof(G));
		memset(degree,0,sizeof(degree));
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(!G[a][b]){
				G[a][b]=true;
				degree[b]++;
			}		
		}
		toposort();
		while(!q.empty()){
			if(q.size()==1)
				printf("%d\n",q.front());
			else
				printf("%d ",q.front());
			q.pop();
		}
	}
	return 0;
}
