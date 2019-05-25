#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;
const int N=5e4+5;

int root[N];

int find(int x){
	return root[x]==x?x:find(root[x]);
}

int main(){
	int n,q;
	while(~scanf("%d%d",&n,&q)){
		for(int i=1;i<=n;i++) root[i]=i;
		for(int i=1;i<=q;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			int t1=find(x),t2=find(y);
			if(t1!=t2){
				root[t1]=t2;
				n--;
			}
		}
		int ans=0;
		printf("%d\n",n);
	}
	return 0;
}
