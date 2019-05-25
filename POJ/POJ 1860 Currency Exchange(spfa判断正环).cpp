#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std; 
const int INF=0x3f3f3f3f;
const int N=105;

double rate[N][N],com[N][N],qcnt[N],dis[N];//dis[i]表示起始货币能换到的货币i的数量
bool vis[N],flag;
int V,E;

bool spfa(int s,double cnt){
	memset(vis,false,sizeof(vis));
	memset(dis,0,sizeof(dis));
	dis[s]=cnt;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=1;i<=V;i++){
			if(rate[k][i]==INF)
				continue;
			double tmp=(dis[k]-com[k][i])*rate[k][i];
			if(tmp>dis[i]){
				dis[i]=tmp;
				if(!vis[i]){
					q.push(i);
					qcnt[i]++;
					//存在正环 
					if(qcnt[i]>=V)
						return true;
					vis[i]=true;
				}
			}
		}
	}
	return false;
}

int main(){
	int s;
	double cnt;
	scanf("%d%d%d%lf",&V,&E,&s,&cnt);
	for(int i=1;i<=V;i++){
		for(int j=1;j<=V;j++){
			rate[i][j]=INF;
		}
	}
	for(int i=1;i<=E;i++){
		int a,b;
		double r1,c1,r2,c2;
		scanf("%d%d%lf%lf%lf%lf",&a,&b,&r1,&c1,&r2,&c2);
		rate[a][b]=r1;
		com[a][b]=c1;
		rate[b][a]=r2;
		com[b][a]=c2;
	}
	if(spfa(s,cnt))
		puts("YES");
	else
		puts("NO");
	return 0;
}
