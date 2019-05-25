#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<algorithm> 
using namespace std; 
const int N=1005;

int n,m;
int mp[N][N],indeg[N];

//判断是否存在环 
bool topo(){
	queue<int>q;
	for(int i=0;i<n;i++){
		if(indeg[i]==0)
			q.push(i);	
	}
	int cnt=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		indeg[t]--;
		cnt++;
		for(int i=0;i<n;i++){
			if(mp[t][i]){
				indeg[i]--;
				if(indeg[i]==0)
					q.push(i);
			}
		}
	}
	if(cnt!=n)
		return false;
	return true;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0)
			break;
		memset(mp,0,sizeof(mp));
		memset(indeg,0,sizeof(indeg));
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			//判断重边 
			if(mp[a][b])
				continue;
			mp[a][b]=1;
			indeg[b]++;
		}
		if(topo())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
