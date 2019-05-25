#include<iostream>
#include<stdio.h>
using namespace std; 
const int N=505;
int cnt[N];//cnt[i]表示根为i的集合的细胞数 
int root[N];
int find(int x){
	int temp=x;
	while(root[x]!=x)
		x=root[x];
	root[temp]=x;
	return x;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			root[i]=i;
			cnt[i]=1;
		}
		char temp[10];
		while(m--){
			scanf("%s",temp);
			if(temp[0]=='U'){
				int a,b;
				scanf("%d%d",&a,&b); 
				int x=find(a);
				int y=find(b);
				if(x!=y){
					root[x]=y;
					cnt[y]+=cnt[x];
					cnt[x]=0;
				}
			}
			else if(temp[0]=='D'){
				int a;
				scanf("%d",&a);
				int x=find(a);
				if(cnt[x]>1){
					if(x==a){
						//如果根就是要分离的细胞
						//那就把根重新变为该细胞所属集合里第一个不是根的细胞（任意一个都可以的，取第一个比较方便） 
						int idx=0;
						for(int i=1;i<=n;i++){
							if(find(i)==a){
								if(i!=a){
									if(idx==0){
										idx=i;
										root[i]=i;
										cnt[i]=cnt[a]-1;
										cnt[a]=1;
									}
									else
										root[i]=idx;
								}
							}
						}
					}
					else{
						cnt[a]=1;
						cnt[x]--;
						root[a]=a;
					}
				}
			}
			else if(temp[0]=='S'){
				int a;
				scanf("%d",&a);
				printf("%d\n",cnt[find(a)]);
			}
			else{
				int count=0;
				for(int i=1;i<=n;i++){
					if(find(i)==i)
						count++;
				}
				printf("%d\n",count);
			}
		}
	}	
}
