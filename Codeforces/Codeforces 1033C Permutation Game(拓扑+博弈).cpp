#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1e5+5;

int n;
int a[N],deg[N],d[N];
bool flag[N];
vector<int>v[N];

void topo(){
	queue<int>q;
	memset(flag,false,sizeof(flag));
	for(int i=1;i<=n;i++){
		if(!deg[i])
			q.push(i);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<v[u].size();i++){
			int t=v[u][i];
			flag[t]=flag[t]|(!flag[u]);
			deg[t]--;
			if(deg[t]==0)
				q.push(t);
		}
	}
}

int main(){
	while(~scanf("%d",&n)){
		memset(deg,0,sizeof(deg));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+a[i];j<=n;j+=a[i]){
				if(a[i]<a[j]){
					v[j].push_back(i);
					deg[i]++;
					d[i]++;
				}
			}
			for(int j=i-a[i];j>=1;j-=a[i]){
				if(a[i]<a[j]){
					v[j].push_back(i);
					deg[i]++;
					d[i]++;
				}
			}
		}
		topo();
		for(int i=1;i<=n;i++){
			if(flag[i])
				printf("A");
			else
				printf("B");
		}
	}
}
