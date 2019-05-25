#include<iostream>
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;

int n,m,w;
int d[8][2]={1,1,0,1,-1,1,-1,0,-1,-1,0,-1,1,-1,1,0};
char fx[10]="DCBAHGFE";
char s[N][N],t[N];;

struct node{
	int x,y,dir;
}ans[N];

bool check(int x,int y,int dir){
	int len=strlen(t);
	for(int i=1;i<len;i++){
		x+=d[dir][0];
		y+=d[dir][1];
		if(x<0||y<0||x>n||y>m||s[x][y]!=t[i]) return false;

	}
	return true;
}


int main(){
	while(cin>>n>>m>>w){
		for(int i=1;i<=n;i++){
			cin>>s[i]+1;
		}
		for(int i=1;i<=w;i++){
			cin>>t;
			ans[i].dir=100;
			for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++){
					if(t[0]==s[j][k]){
						for(int q=0;q<8;q++){
							if(check(j,k,q)){
								if(ans[i].dir>q){
									ans[i].dir=q;
									ans[i].x=j;
									ans[i].y=k;
								}
								break;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=w;i++){
			cout<<ans[i].x<<" "<<ans[i].y<<" "<<fx[ans[i].dir]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
