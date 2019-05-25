#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=2e2+5;
const int INF=0x3f3f3f3f;

int n;
int dis[N],busy[N],qcnt[N],cost[N][N];
bool vis[N],cir[N];

//����j,k�������շ� 
int cal_amt(int j,int i){
	return (busy[i]-busy[j])*(busy[i]-busy[j])*(busy[i]-busy[j]);
}
//�������x���ܵ���ĵ� 
void dfs(int x){
	cir[x]=true;
	for(int i=1;i<=n;i++){
		if(cost[x][i]==1&&!cir[i])
			dfs(i);
	}
}

bool spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	memset(qcnt,0,sizeof(qcnt));
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=1;i<=n;i++){
			//���������ϵĵ�
			if(i==k||cost[k][i]==-1||cir[i])
				continue;
			if(dis[k]+cal_amt(k,i)<dis[i]){
				dis[i]=dis[k]+cal_amt(k,i);
				if(!vis[i]){
					q.push(i);
					qcnt[i]++;
					//�����ڸ�������dfs������и����ϵĿɴ��
					if(qcnt[i]>=n)
						dfs(i);
					vis[i]=true;
				}
			}
		}
	}
}

int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		memset(cost,-1,sizeof(cost));
		memset(cir,false,sizeof(cir));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&busy[i]);
		}
		int m;
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			cost[a][b]=1;
		}
		int q;
		scanf("%d",&q);
		spfa(1);
		printf("Case %d:\n",++cas);
		for(int i=1;i<=q;i++){
			int des;
			scanf("%d",&des);
			//���õ��ڸ����ϡ������޷���������շ�С��3���'?' 
			if(cir[des]||dis[des]==INF||dis[des]<3)
				puts("?");
			else
				printf("%d\n",dis[des]);
		}
	}
	return 0;
}
