#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
using namespace std;
const int N=1e6+5; 

int big,small,n;
int heap[N];
//维护大根堆 
void Max(int idx){
	int l=LC(idx);
	int r=RC(idx);
	big=idx;
	if(l<=n&&heap[big]<heap[l])
		big=l;
	if(r<=n&&heap[big]<heap[r])
		big=r;
	if(big!=idx){
		swap(heap[big],heap[idx]);
		Max(big);
	}
}
//维护小根堆 
void Min(int idx){
	int l=LC(idx);
	int r=RC(idx);
	small=idx;
	if(l<=n&&heap[small]>heap[l])
		small=l;
	if(r<=n&&heap[small]>heap[r])
		small=r;
	if(small!=idx){
		swap(heap[small],heap[idx]);
		Min(small);
	}
}


int main(){
	int m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d",&heap[i]);
		}
		for(int i=n/2;i>=1;i--)
			Min(i);
		int t=n;
		for(int i=t;i>=2;i--){
			swap(heap[1],heap[i]);
			n--;
			Min(1);
		}
		for(int i=t;i>=t-m+1;i--){
			printf("%d%c",heap[i],(i==m?'\n':' '));
		}
	}
	return 0;
}
