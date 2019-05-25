#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	string num;
	int step;
	int use1;
	int use2;
};
queue<node>q;
int vis[10][10][10][10][10][5][5];

string cal1(string x,int st){
	swap(x[st],x[st+1]);
	return x;
}

string cal2(string x,int st){
	x[st]=(x[st]-'0'+1)%10+'0';
	return x;
}

string cal3(string x,int st){
	int t=x[st]-'0';
	x[st]=t*2%10+'0';
	return x;
}


void judge(string x,int u1,int u2,int step){
	int t1=x[0]-'0',t2=x[1]-'0',t3=x[2]-'0',t4=x[3]-'0',t5=x[4]-'0';
	if(step<vis[t1][t2][t3][t4][t5][u1][u2]){
		vis[t1][t2][t3][t4][t5][u1][u2]=step;
		q.push(node{x,step,u1,u2});
	}
}

void bfs(string st){
	q.push(node{st,0,0,0});
	while(!q.empty()){
		node pre=q.front();
		int u1=pre.use1;
		int u2=pre.use2;
		q.pop();
		string now;
		for(int i=1;i<=3;i++){
			if(i==1){
				for(int j=0;j<4;j++){
					now=cal1(pre.num,j);
					judge(now,u1,u2,pre.step+1);
				}
			}
			if(i==2){
				for(int j=0;j<5;j++){
					if(u1+1>3) continue;
					now=cal2(pre.num,j);
					judge(now,u1+1,u2,pre.step+1);
				}
			}
			if(i==3){
				for(int j=0;j<5;j++){
					if(u2+1>2) continue;
					now=cal3(pre.num,j);
					judge(now,u1,u2+1,pre.step+1);
				}	
			}
		}
	}
}

/*
12435
99999
12374
*/

int main(){
	memset(vis,0x3f,sizeof(vis));
	for(int i=0;i<=3;i++){
		for(int j=0;j<=2;j++){
			vis[1][2][3][4][5][i][j]=0;
		}
	}
	FAST_IO;
	bfs("12345");
	string x;
	while(cin>>x){
		int ans=INF;
		int t1=x[0]-'0',t2=x[1]-'0',t3=x[2]-'0',t4=x[3]-'0',t5=x[4]-'0';
		for(int i=0;i<=3;i++){
			for(int j=0;j<=2;j++){
				ans=min(ans,vis[t1][t2][t3][t4][t5][i][j]);
			}
		}
		if(ans==INF)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}

