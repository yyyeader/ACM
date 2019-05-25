#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false)
using namespace std;
const int N=2e5+5;

int cnt;
int a[N],c[N],vis[N];
stack<int>sk; 
vector<int>v[N],circle[N];

//dfs�һ�,vis[i]==0��ʾδ������, vis[i]==1��ʾ�������һ���ջ��, vis[i]==2��ʾ���������ѳ�ջ 
void dfs(int u){
	vis[u]=1;
	sk.push(u);
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(vis[t]==2) continue;
		if(!vis[t]) dfs(t);
		else{
			cnt++;
			while(!sk.empty()){
				int top=sk.top();sk.pop();
				vis[top]=2;
				circle[cnt].push_back(top);
				if(top==t) break;
			}
		}
	}
	if(vis[u]!=2){
		vis[u]=2;sk.pop();
	}
}

int main(){
	FAST_IO;
	int n;
	cin>>n;
	LL ans=0;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i].push_back(a[i]);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])
			dfs(i);
	}
	for(int i=1;i<=cnt;i++){
		int mmin=1e9;
		for(int j=0;j<circle[i].size();j++){
			int t=circle[i][j];
			mmin=min(mmin,c[t]);
		}
		ans+=mmin;
	}
	cout<<ans<<endl;
	return 0;
}
