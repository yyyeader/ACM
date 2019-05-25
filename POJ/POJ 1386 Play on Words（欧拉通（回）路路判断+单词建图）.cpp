#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define CLR(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int N=30;

int indeg[N],outdeg[N],root[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

void init(){
	CLR(indeg,0);
	CLR(outdeg,0);
	for(int i=0;i<26;i++)
		root[i]=i;
}

int main(){
	int n,t;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		char str[1005];
		for(int i=1;i<=n;i++){
			int u,v;
			scanf("%s",str);
			//u->v的有向边 
			u=str[0]-'a';
			v=str[strlen(str)-1]-'a';
			if(find(u)!=find(v))
				root[find(u)]=find(v);
			indeg[v]++;
			outdeg[u]++;
		}
		bool flag=true;
		int cnt=0,chu=0,ru=0;
		for(int i=0;i<26;i++){
			if(find(i)==i&&(indeg[i]+outdeg[i])>0)
				cnt++;
			if(indeg[i]!=outdeg[i]){
				if(indeg[i]-1==outdeg[i])
					ru++;
				else if(indeg[i]+1==outdeg[i])
					chu++;
				else
					flag=false;	
			}
		}
		//欧拉回路和通路都符合题目条件 
		if(flag&&cnt==1&&(chu==1&&ru==1||chu==0&&ru==0))
			puts("Ordering is possible.");
		else
			puts("The door cannot be opened.");
	}
	return 0;
}
