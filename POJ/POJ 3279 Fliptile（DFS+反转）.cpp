#include<cstdio>
#include<cstring>
using namespace std;
const int N=20;

int n,m;
bool flag;
int map[N][N],sta[N][N],tmp[N][N];//sta表示踩或不踩
int d[5][2]={{0,1},{1,0},{0,0},{0,-1},{-1,0}};


//反转坐标为(i，j)的格子
void reverse(int i,int j,int s[][N]){
	for(int k=0;k<5;k++){
		int x=i+d[k][0];
		int y=j+d[k][1];
		s[x][y]=!s[x][y];
	}
}

void dfs(int y){
	if(flag)
		return;
	if(y>=1){
		//不踩
		sta[1][y]=0;
		dfs(y-1);
		//踩
		sta[1][y]=1;
		reverse(1,y,map);
		dfs(y-1);
		reverse(1,y,map);
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				tmp[i][j]=map[i][j];
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				sta[i][j]=0;
				if(tmp[i-1][j]==1){
					reverse(i,j,tmp);
					sta[i][j]=1;
				}
			}
		}

		bool sign=true;
		for(int i=1;i<=m;i++){
			if(tmp[n][i]==1){
				sign=false;
				break;
			}
		}
		if(sign){
			flag=true;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(j==m)
						printf("%d\n",sta[i][j]);
					else
						printf("%d ",sta[i][j]);
				}
			}
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(sta,0,sizeof(sta));
		flag=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
                scanf("%d",&map[i][j]);
			}
		}
		dfs(m);
		if(!flag)
			puts("IMPOSSIBLE");
	}
	return 0;
}
