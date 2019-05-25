#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+5;

int n,k;
int vis[N];


struct node{
	int val,step;
}pre,now;

int bfs(){
	queue<node>q;
	now.val=n;
	now.step=0;
	q.push(now);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(int i=1;i<=3;i++){
			int t;
			if(i==1)
				t=pre.val+1;
			if(i==2)
				t=pre.val-1;
			if(i==3)
				t=pre.val*2;
			if(t<0||t>N||vis[t])
				continue;
			if(t==k)
				return pre.step+1;
			vis[t]=1;
			now.val=t;
			now.step=pre.step+1;
			q.push(now);
		}
	}
	return 0;
}

int main(){
	while(~scanf("%d%d",&n,&k)){
		memset(vis,0,sizeof(vis));
		if(n==k)
			puts("0");
		else
			printf("%d\n",bfs());
	}
	return 0;
} 
