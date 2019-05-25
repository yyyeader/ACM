#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int N=105;
const int INF=0x3f3f3f;
 
int main(){
	int A[N][N];
	int T;
	cin>>T;
	while(T--){
		int m,n;
		set<int>st[N][N];
		cin>>n>>m; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				A[i][j]=INF;
			} 
		}
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			A[x][y]=A[y][x]=1;
		}	
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(A[i][j]>(A[i][k]+A[k][j])){
						A[i][j]=A[i][k]+A[k][j];
					}
				}
			}
		}
		
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(A[i][j]==(A[i][k]+A[k][j])){
						st[i][j].insert(k);
					}
				}
			}
		}
//		set<int>::iterator it;
//		for(it=st[1][2].begin();it!=st[1][2].end();it++){
//			cout<<*it<<"¡¡"; 
//		} 
//		cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					if(j==n)
						cout<<"0"<<endl;
					else
						cout<<"0 ";
				}
				else{
					if(st[i][j].size()!=0||A[i][j]!=INF){
						if(j==n)
							cout<<st[i][j].size()+2<<endl;
						else
							cout<<st[i][j].size()+2<<" ";
					}
					else{
						if(j==n)
							cout<<"0"<<endl;
						else
							cout<<"0 ";
					}
				}
			}
		}		
	}	
} 
