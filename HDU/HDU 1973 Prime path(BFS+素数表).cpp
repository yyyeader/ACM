#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e4+5;

int n,res,ans;
int vis[N];
int Pow[4]={1,10,100,1000};
bool prime[N];

void is_prime(){
	for(int i=2;i<N;i++){
		prime[i]=true;
	}
	for(int i=2;i*i<N;i++){
		if(prime[i]){
			for(int j=i*i;j<N;j+=i)
				prime[j]=false;
		}
	}
}

struct node{
	int step;
	int num;
}pre,now;

bool bfs(){
	queue<node>q;
	now.num=n;
	now.step=0;
	q.push(now);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		//枚举四位,从0~9(千位不能为0),找出素数入队，不断bfs直到找出答案 
		for(int i=0;i<4;i++){	
			for(int j=0;j<=9;j++){
				int t=pre.num;
				if(i==0)
					t-=t%10*Pow[i];
				if(i==1)
					t-=t%100/10*Pow[i];
				if(i==2)
					t-=t%1000/100*Pow[i];
				if(i==3)
					t-=t/1000*Pow[i];
				if(i==3&&j==0)
					continue;
				t+=j*Pow[i];
				if(t==pre.num||!prime[t]||vis[t])
					continue;
				if(t==res){
					ans=pre.step+1;
					return true;
				}
				vis[t]=1;
				now.num=t;
				now.step=pre.step+1;			
				q.push(now);
			}				
		}
	}
	return false;
}

int main(){
	is_prime();
	int t;
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&res);
		if(n==res){
			puts("0");
			continue;
		}
		ans=0;
		if(bfs())
			printf("%d\n",ans);
		else
			puts("Impossible");
	}
	return 0;
} 
