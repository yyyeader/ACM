#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5e4+5;
vector<int>v[N];
int tmp[N];
long long count=0,mem=0;//count��������mem��Ա�� 

void dfs(int n){
	if(!tmp[n])
		return; 
	tmp[n]=0;//��ʾ������Ѿ��߹� 
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
			if(count!=mem*(mem-1)){//Ӧ����count=mem*(mem-1)������5���ˣ�ÿ���˶�Ҫ�ͱ���ĸ����й�ϵ����ô������count=5*��4-1��=20 
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
