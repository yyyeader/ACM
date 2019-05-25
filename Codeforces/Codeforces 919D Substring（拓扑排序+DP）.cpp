#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm> 
using namespace std;
const int N=3e5+5;

int n,m;
int f[N][26],deg[N];
char ch[N];
vector<int>v[N];

int toposort(){
	queue<int>q;
	int ans=-1;
	for(int i=1;i<=n;i++){
		if(deg[i]==0)
			q.push(i);
	}
	int cnt=0;
	while(!q.empty()){
		int k=q.front();
		q.pop();
		cnt++;
		f[k][ch[k]-'a']++;
		ans=max(f[k][ch[k]-'a'],ans);
		for(int i=0;i<v[k].size();i++){
			int t=v[k][i];
			deg[t]--;
			for(int j=0;j<26;j++){
				f[t][j]=max(f[t][j],f[k][j]);
			}
			if(deg[t]==0){
				q.push(t);
			}		
		}
	}
	if(cnt!=n)
		ans=-1;
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		scanf("%c",&ch[i]);
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		deg[b]++;
		v[a].push_back(b);
	}
	printf("%d\n",toposort());
	return 0;
}
