#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e4+5;

int root[N],val[N];

struct node{
	int a,b,c;
}arr[N];

int find(int x){
	if(root[x]==x)
		return x;
	int tmp=find(root[x]);
	val[x]=(val[x]+val[root[x]])%3;
	return root[x]=tmp;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=m;i++){
			char c;
			scanf("%d%c%d",&arr[i].a,&c,&arr[i].b);
			if(c=='=')	arr[i].c=0;
			if(c=='<')	arr[i].c=2;
			if(c=='>')	arr[i].c=1;
		}
		bool flag;
		int line=0,sum=0,ans;
		//枚举0~n-1 
		for(int i=0;i<n;i++){
			//初始化 
			memset(val,0,sizeof(val));
			for(int j=0;j<n;j++)
				root[j]=j;
			flag=false;
		
			for(int j=1;j<=m;j++){
				int a=arr[j].a,b=arr[j].b,c=arr[j].c;
				if(a==i||b==i)
					continue;
				int t1=find(a);
				int t2=find(b);
				if(t1==t2){
					if((val[a]+c)%3!=val[b]){
						//所有出问题的地方取最大值 
						line=max(line,j);
						flag=true;
						break;
					}
				}
				else{
					root[t2]=t1;
					val[t2]=(val[a]-val[b]+c+3)%3;
				}
			}
			//没有矛盾 
			if(!flag){
				sum++;
				ans=i;
			}
		}
		//判断sum的个数 
		if(sum==0)
			puts("Impossible");
		else if(sum>1)
			puts("Can not determine");
		else
			printf("Player %d can be determined to be the judge after %d lines\n",ans,line);
	}
	return 0;
}
