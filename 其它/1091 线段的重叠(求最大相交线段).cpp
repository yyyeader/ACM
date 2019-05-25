#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e4+5;

struct node{
	int x,y;
	bool operator <(const node &b)const{
		return x==b.x?y>b.y:x<b.x;
	}
}a[N];


int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n);
	int e=a[1].y,dis=0;
	for(int i=2;i<=n;i++){
		if(a[i].y<=e)
			dis=max(dis,a[i].y-a[i].x);
		else
			dis=max(dis,e-a[i].x);
		e=max(e,a[i].y);
	} 
	printf("%d\n",dis);
	return 0;
}
