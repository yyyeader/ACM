#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int M=2e4+5;
const int N=1e4+5;

struct node{
	int to,next;
	string w;
}edge[M];

int idx;
int indeg[N],outdeg[N],head[N];
string str[M];
bool vis[M];
stack<string>sk;

void init(){
	idx=1;
	CLR(head,0);
	CLR(indeg,0);
	CLR(outdeg,0);
	CLR(vis,false);
	while(!sk.empty()){
		sk.pop();
	}
}

void addedge(int u,int v,string w){
	edge[idx].to=v;
	edge[idx].w=w;
	edge[idx].next=head[u];
	head[u]=idx++;
}

void dfs(int u){
	for(int &j=head[u];j;j=edge[j].next){
		node t=edge[j];
		if(!vis[j]){
			vis[j]=true;
			dfs(t.to);
			sk.push(t.w);
		}
	}
}

int main(){
	FAST_IO;
	int t;
	cin>>t;
	while(t--){
		init();
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>str[i];
		sort(str,str+n);
		int start=100;
		//字典序大的先加入，因为静态邻接表是反向添加的 
		for(int i=n-1;i>=0;i--){
			int u,v;
			u=str[i][0]-'a';
			v=str[i][str[i].length()-1]-'a';
			outdeg[u]++;
			indeg[v]++;
			addedge(u,v,str[i]);
			start=min(start,min(u,v));
		}
		int chu=0,ru=0;
		bool flag=true;
		for(int i=0;i<26;i++){
			if(indeg[i]+outdeg[i]==0)
				continue;
			if(indeg[i]!=outdeg[i]){
				if(indeg[i]+1==outdeg[i]){
					chu++;
					start=i;				//如果有一个出度比入度大1的点，就从这个点出发，否则从最小的点出发
				}
				else if(indeg[i]-1==outdeg[i])
					ru++;
				else
					flag=false;
			}
		}
		if(flag&&(chu==1&&ru==1||chu==0&&ru==0)){
			dfs(start);
			if(sk.size()==n){
				while(!sk.empty()){
					if(sk.size()==1)
						cout<<sk.top()<<endl;
					else
						cout<<sk.top()<<".";
					sk.pop();
				}
			}
			else
				puts("***");
		}
		else
			puts("***");
	}
	return 0;
}
