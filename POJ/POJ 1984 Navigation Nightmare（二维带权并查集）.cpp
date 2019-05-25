#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e4+5;
int root[N],val[N][2],res[N];//val[][]用来记录权值，val[][0]表示南北方向的偏移量，val[][1]表示东西方向的偏移量 

struct node{
	int a,b,len;
	char det[5];
}arr[N];

struct Node{
	int a,b,id;
	Node(){}
	Node(int l,int r,int c){
		a=l;
		b=r;
		id=c;
	}
};
vector<Node>v[N];

int find(int x){
	if(root[x]==x)
		return x;
	int tmp=find(root[x]);
	val[x][0]+=val[root[x]][0];
	val[x][1]+=val[root[x]][1];
	return root[x]=tmp;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		root[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%s",&arr[i].a,&arr[i].b,&arr[i].len,arr[i].det);
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int a,b,num;
		scanf("%d%d%d",&a,&b,&num);
		v[num].push_back(Node(a,b,i));
	}
	
	for(int i=1;i<=m;i++){
		int a=arr[i].a,b=arr[i].b,len=arr[i].len;
		int t1=find(a);
		int t2=find(b);
		if(t1!=t2){
			root[t2]=t1;
			if(arr[i].det[0]=='N'){
				val[t2][0]=val[a][0]-val[b][0]+len;//val[t2][0]+val[b][0]=val[a][0]+len即a点向北走len距离到b点 
				val[t2][1]=val[a][1]-val[b][1];//东西方向没有发生偏移 
			}
			if(arr[i].det[0]=='S'){
				val[t2][0]=val[a][0]-val[b][0]-len;//val[t2][0]+val[b][0]=val[a][0]+len即a点向南走len距离到b点 
				val[t2][1]=val[a][1]-val[b][1];
			}
			if(arr[i].det[0]=='W'){
				val[t2][1]=val[a][1]-val[b][1]-len;//同理 
				val[t2][0]=val[a][0]-val[b][0];
			}
			if(arr[i].det[0]=='E'){
				val[t2][1]=val[a][1]-val[b][1]+len;
				val[t2][0]=val[a][0]-val[b][0];
			}			
		}
		for(int j=0;j<v[i].size();j++){
			a=v[i][j].a;
			b=v[i][j].b;
			t1=find(a);
			t2=find(b);
			if(t1!=t2)//两点不在同一个并查集中则两点间没有通路 
				res[v[i][j].id]=-1;
			else 
				res[v[i][j].id]=abs(val[a][0]-val[b][0])+abs(val[a][1]-val[b][1]);
		}
	}
	for(int i=1;i<=q;i++){			
		printf("%d\n",res[i]);
	}
	return 0;
}
