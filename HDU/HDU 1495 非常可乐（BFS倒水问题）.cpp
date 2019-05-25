#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=105;
int A,B,C,ans;
int vis[N][N][N];

struct node{
	int a,b,c,step;
}pre,now;

bool bfs(){
	queue<node>q;
	now.a=A;
	now.b=0;
	now.c=0;
	now.step=0;
	vis[A][0][0]=1;
	q.push(now);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(int i=1;i<=6;i++){
			int a,b,c;
			a=pre.a;
			b=pre.b;
			c=pre.c;
			if(i==1){
				if(a>B-b){
					a-=(B-b);
					b=B;
				}
				else{
					b+=a;
					a=0;	
				}
			}
			if(i==2){
				a+=b;
				b=0;	
			}
			if(i==3){
				if(b>C-c){
					b-=(C-c);
					c=C;
				}
				else{
					c+=b;
					b=0;		
				}
			}
			if(i==4){
				if(c>B-b){
					c-=(B-b);
					b=B;
				}
				else{
					b+=c;
					c=0;
				}
			}
			if(i==5){
				if(a>C-c){
					a-=(C-c);
					c=C;
				}
				else{
					c+=a;
					a=0;
				}
			}
			if(i==6){
				a+=c;
				c=0;
			}
			if(vis[a][b][c])
				continue;
			if(b==a&&b==A/2||a==c&&a==A/2){
				ans=pre.step+1;
				return true;
			}
			vis[a][b][c]=1;
			now.a=a;
			now.b=b;
			now.c=c;
			now.step=pre.step+1;
			q.push(now);
		}
	}
	return false;
}


int main(){
	while(~scanf("%d%d%d",&A,&B,&C)){
		memset(vis,0,sizeof(vis));
		ans=0;
		if(A==0&&B==0&&C==0)	
			break;
		if(A&1)
			puts("NO");
		else if(bfs())
			printf("%d\n",ans);
		else
			puts("NO");
	}
	return 0;
}
