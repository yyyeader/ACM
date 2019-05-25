#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<iostream>
using namespace std; 

int A,B,C;
int vis[105][105];


struct node{
	int va,vb,step;
	string path;
}pre,now,ans;

bool bfs(){
	queue<node>q;
	now.step=0;
	now.path="";
	now.va=0;
	now.vb=0;
	q.push(now);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		if(pre.va==C||pre.vb==C){
			ans=pre;
			return true;
		}
		for(int i=1;i<=6;i++){
			int a=pre.va,b=pre.vb;		
			if(i==1)
				a=A;
			if(i==2)
				a=0;
			if(i==3){
				if(B>=a+b){
					b+=a;
					a=0;
				}
				else{
					a-=B-b;
					b=B;	
				}
			}
			if(i==4)
				b=B;
			if(i==5)
				b=0;
			if(i==6){
				if(A>=a+b){
					a+=b;
					b=0;
				}
				else{
					b-=A-a;
					a=A;
				}
			}
			if(vis[a][b])
				continue;
			
			vis[a][b]=1;
			now.path=pre.path;
			now.path+=(i+'0');
			now.step=pre.step+1;
			now.va=a;
			now.vb=b;
			q.push(now);
		}
	}
	return false;
}

int main(){
	while(~scanf("%d%d%d",&A,&B,&C)){
		memset(vis,0,sizeof(vis));
		if(bfs()){
			printf("%d\n",ans.step);
			string s=ans.path;
			for(int i=0;i<s.size();i++){
				if(s[i]=='1')
					puts("FILL(1)");
				if(s[i]=='2')
					puts("DROP(1)");
				if(s[i]=='3')
					puts("POUR(1,2)");
				if(s[i]=='4')
					puts("FILL(2)");
				if(s[i]=='5')
					puts("DROP(2)");
				if(s[i]=='6')
					puts("POUR(2,1)");
			}
		}
		else
			puts("impossible");
	}
	return 0;
}
