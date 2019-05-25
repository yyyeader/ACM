#include<iostream>
#include<cstring>
#include<cstdio>
#define CLR(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int N=1e3+5;

int n,m;
int root[N],indeg[N],outdeg[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;		
		CLR(indeg,0);
		CLR(outdeg,0);
		for(int i=1;i<=n;i++)
			root[i]=i;
		scanf("%d",&m);
		int a,b,x,y;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			indeg[b]++;
			outdeg[a]++;
			x=find(a),y=find(b);
			if(x!=y)
				root[x]=y;
		}
		bool flag=true;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(find(i)==i)
				cnt++;
			if((indeg[i]+outdeg[i])%2!=0){
				flag=false;
				break;
			}
		}
		if(flag&&cnt==1)
			puts("1");
		else
			puts("0");
	}
	return 0;
}
