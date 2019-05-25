#include<cstdio>
const int N=5e4+5;

int root[N*3];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

bool same(int a,int b){
	return find(a)==find(b);
}

void unite(int a,int b){
	if(find(a)!=find(b))
		root[find(a)]=find(b);
}

//元素x,x+N,x+2*N分别代表x-A,x-B,x-C 
int main(){
	int N,K,ans=0;
	scanf("%d%d",&N,&K);
	for(int i=1;i<=3*N;i++){
		root[i]=i;
	}
	while(K--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(x>N||y>N){
			ans++;
			continue;
		}
		if(t==1){
			//"x,y属于同一类" 的信息 
			if(same(x,y+N)||same(x,y+2*N))
				ans++;
			else{
				unite(x,y);
				unite(x+N,y+N);
				unite(x+2*N,y+2*N);
			}
		}
		else{
			//"x吃y"的信息 
			if(same(x,y)||same(x,y+2*N))
				ans++;
			else{
				unite(x,y+N);
				unite(x+N,y+2*N);
				unite(x+2*N,y);
			}
		}
	}
	printf("%d\n",ans);
}
