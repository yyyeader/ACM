#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5e4+5;
vector<int>v[N];
int tmp[N];
long long count=0,mem=0;//count连线数，mem成员数 

void dfs(int n){
	if(!tmp[n])
		return; 
	tmp[n]=0;//表示这个点已经走过 
	mem++;	
	for(int i=0;i<v[n].size();i++){
		count++;
		dfs(v[n][i]);
	}
	return;
}

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		tmp[x]=1;
		tmp[y]=1;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bool sign=true;
	for(int i=1;i<=m;i++){
		if(tmp[i]){
			dfs(i);
			if(count!=mem*(mem-1)){//应满足count=mem*(mem-1)，比如5个人，每个人都要和别的四个人有关系，那么连线数count=5*（4-1）=20 
				sign=false;
				break;
			}
			count=mem=0;
		}
	}
	if(sign){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}
